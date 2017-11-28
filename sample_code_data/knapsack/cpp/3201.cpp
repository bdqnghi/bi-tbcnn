#include <ilcplex/ilocplex.h>
#include <ilcplex/cplex.h>
ILOSTLBEGIN
#include <string>
#include <vector>

#define TOL 1E-05

int main(int argc, char **argv) {

  // Datos de la instancia de knapsack.
  int n = 8;
  double pj[] = {15, 100, 90, 60, 40, 15, 10, 1};
  double wj[] = {2, 20, 20, 30, 40, 30, 60, 10};
  double c = 102;
    
  // Genero el problema de cplex.
  int status;
  CPXENVptr env; // Puntero al entorno.
  CPXLPptr lp; // Puntero al LP
   
  // Creo el entorno.
  env = CPXopenCPLEX(&status);

    
  if (env == NULL) {
    cerr << "Error creando el entorno" << endl;
    exit(1);
  }
    
  // Creo el LP.
  lp = CPXcreateprob(env, &status, "Knapsack instance");

    
  if (lp == NULL) {
    cerr << "Error creando el LP" << endl;
    exit(1);
  }

    
  // Definimos las variables. No es obligatorio pasar los nombres de las variables, pero facilita el debug. La info es la siguiente:
  double *ub, *lb, *objfun; // Cota superior, cota inferior, coeficiente de la funcion objetivo.
  char *xctype, **colnames; // tipo de la variable (por ahora son siempre continuas), string con el nombre de la variable.
  ub = new double[n]; 
  lb = new double[n];
  objfun = new double[n];
  xctype = new char[n];
  colnames = new char*[n];
  
  for (int i = 0; i < n; i++) {
    ub[i] = 1.0;
    lb[i] = 0.0;
    objfun[i] = pj[i];
    xctype[i] = 'C'; // 'C' es continua, 'B' binaria, 'I' Entera. Para LP (no enteros), este parametro tiene que pasarse como NULL. No lo vamos a usar por ahora..
    // Nombre de la variable.
    stringstream name;
    name << "x_" << i;
    string namestr(name.str());
    int len = strlen(namestr.c_str());
    colnames[i] = new char[len+1];
    strcpy(colnames[i], namestr.c_str());
  }
  
  // Agrego las columnas.
  status = CPXnewcols(env, lp, n, objfun, lb, ub, NULL, colnames);
  
  if (status) {
    cerr << "Problema agregando las variables CPXnewcols" << endl;
    exit(1);
  }
  
  // Libero las estructuras.
  for (int i = 0; i < n; i++) {
    delete[] colnames[i];
  }
  
  delete[] ub;
  delete[] lb;
  delete[] objfun;
  delete[] xctype;
  delete[] colnames;

  // CPLEX pór defecto minimiza. Le cambiamos el sentido a la funcion objetivo.
  CPXchgobjsen(env, lp, CPX_MAX);

  // Generamos de a una las restricciones. En este caso, hay una sola.
  // Estos valores en genral estan fijos. Indican:
  // ccnt = numero nuevo de columnas en las restricciones.
  // rcnt = cuantas restricciones es estan pasando en las restricciones.
  // nzcnt = # de coeficientes != 0 a ser agregados a la matriz. Solo se pasan los valores que no son cero.
  // zero = 0. En realidad, esto reemplaza al parametro rmatbeg ya que se agrega una unica restriccion. Si se agregaran
  // de a mas de una, rmatbeg (ver documentacion de CPXaddrows) deberia tener la posicion en la que comienza cada 
  // restriccion.
  int ccnt = 0, rcnt = 1, nzcnt = 0, zero = 0; 
  char sense = 'L'; // Sentido de la desigualdad. 'G' es mayor o igual y 'E' para igualdad.
  double rhs = c; // termino independiente. En nuestro caso, la capacidad.
  int *cutind = new int[n]; // Array con los indices de las variables con coeficientes != 0 en la desigualdad.
  double *cutval = new double[n]; // Array que en la posicion i tiene coeficiente ( != 0) de la variable cutind[i] en la restriccion.
  // Podria ser que algun coeficiente sea cero. Pero a los sumo vamos a tener n coeficientes. CPLEX va a leer hasta la cantidad
  // nzcnt que le pasemos.

  // Restricciones de grado de salida.
  for (int i = 0; i < n; i++) {
    // Solo consdieramos la varaible en la restriccion si el coeficiente es != 0.
    if (fabs(wj[i]) > TOL) {
      cutind[nzcnt] = i;
      cutval[nzcnt] = wj[i];
      nzcnt++;
    }
  }
  // Esta rutina agrega la restriccion al lp.
  status = CPXaddrows(env, lp, ccnt, rcnt, nzcnt, &rhs, &sense, &zero, cutind, cutval, NULL, NULL);
    
  
  if (status) {
    cerr << "Problema agregando restriccion de capacidad." << endl;
    exit(1);
  }
      
  // Seteo de algunos parametros.
  // Para desactivar la salida poern CPX_OFF.
  status = CPXsetintparam(env, CPX_PARAM_SCRIND, CPX_ON);
    
  if (status) {
    cerr << "Problema seteando SCRIND" << endl;
    exit(1);
  }
    
  // Por ahora no va a ser necesario, pero mas adelante si. Setea el tiempo
  // limite de ejecucion.
  status = CPXsetdblparam(env, CPX_PARAM_TILIM, 3600);
  
  if (status) {
    cerr << "Problema seteando el tiempo limite" << endl;
    exit(1);
  }
 
  // Escribimos el problema a un archivo .lp.
  status = CPXwriteprob(env, lp, "knapsack.lp", NULL);
    
  if (status) {
    cerr << "Problema escribiendo modelo" << endl;
    exit(1);
  }
    
  // Tomamos el tiempo de resolucion utilizando CPXgettime.
  double inittime, endtime;
  status = CPXgettime(env, &inittime);

  // Optimizamos el problema.
  status = CPXlpopt(env, lp);

  status = CPXgettime(env, &endtime);

  if (status) {
    cerr << "Problema optimizando CPLEX" << endl;
    exit(1);
  }
    
  double objval;
  status = CPXgetobjval(env, lp, &objval);
    
  if (status) {
    cerr << "Problema obteniendo mejor solucion entera" << endl;
    exit(1);
  }
    
  cout << "Datos de la resolucion: " << "\t" << objval << "\t" << (endtime - inittime) << endl; 

  // Tomamos los valores de la solucion y los escribimos a un archivo.
  std::string outputfile = "knapsack.sol";
  ofstream solfile(outputfile.c_str());

  // Tambien imprimimos el estado de la solucion.
  int solstat;
  char statstring[510];
  CPXCHARptr p;

  solstat = CPXgetstat(env, lp);
  p = CPXgetstatstring(env, solstat, statstring);
  string statstr(statstring);
    
  // Tomamos los valores de todas las variables. Estan numeradas de 0 a n-1.
  double *sol = new double[n];
  status = CPXgetx(env, lp, sol, 0, n - 1);

  if (status) {
    cerr << "Problema obteniendo la solucion del LP" << endl;
    exit(1);
  }

    
  // Solo escribimos las variables distintas de cero (tolerancia, 1E-05).
  solfile << "Status de la solucion: " << statstr << endl;
  for (int i = 0; i < n; i++) {
    if (sol[i] > TOL) {
      solfile << "x_" << i << " = " << sol[i] << endl;
    }
  }

  
  delete [] sol;
  solfile.close();

	return 0;
}
