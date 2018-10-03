#include "Grafo.h"
#include "Lista.h"

#include <string>
#include <iostream>

using namespace std;

template <class C>
void dfs(const Grafo<C> & grafo, Lista<int> & recorrido,
	 int v, bool visitados[])
{
	visitados[v] = true;

	Lista<typename Grafo<C>::Arco> adyacentes;
	grafo.devolverAdyacentes(v, adyacentes);
	typename Lista<typename Grafo<C>::Arco>::Iterador ady = adyacentes.devolverIterador();
	while (!ady.llegoAlFinal())
	{
		int w = ady.elementoActual().devolverAdyacente();
		if (!visitados[w])
		{
			dfs(grafo, recorrido, w, visitados);
		}
		ady.avanzar();
	}	
	recorrido.agregarFinal(v);
}


template <typename C>
void mostrarRecorridoGrafo(const Grafo<C> & grafo, const Lista<int> & recorrido, const char impr[])
{
	Lista<int>::ConstIterador v = recorrido.devolverIterador();
	while (!v.llegoAlFinal())
	{
		cout << impr[v.elementoActual()] << "\n";
		v.avanzar();
	}
}


int main(int argc, char **argv)
{
	Grafo<int> g;
	enum {A, B, C, D, E, F, G};
	g.agregarVertice(A);
	g.agregarVertice(B);
	g.agregarVertice(C);
	g.agregarVertice(D);
	g.agregarVertice(E);
	g.agregarVertice(F);
	g.agregarVertice(G);

	g.agregarArco(A, B, 1);
	g.agregarArco(A, C, 1);
	g.agregarArco(A, D, 1);
	g.agregarArco(B, F, 1);
	g.agregarArco(C, E, 1);	
	g.agregarArco(D, G, 1);
	g.agregarArco(E, F, 1);

	Lista<int> recorrido;
	const char impr[] = "ABCDEFG";
	bool visitados[] = {false, false, false, false, false, false, false};
	dfs(g, recorrido, 0, visitados);
	mostrarRecorridoGrafo(g, recorrido, impr);
	
	return 0;
}

