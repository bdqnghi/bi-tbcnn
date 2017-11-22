package BubleSort;

public class Principal { 

public static void main(String[] args){

int[] vet = {5,10,2,6,3,2};
int aux;
int x;
int y;
int cont = 0;
System.out.println("Numeros Desordenados");

	for (x = 0; x < vet.length; x++) { 
	
		System.out.print (" "+vet[x]); // imprime numeros desordenados

}  
 //organiza os valores.
	for ( x = 0; x < vet.length; x++) { 

		for (y = 0; y < vet.length - 1; y++,cont++) { 
			if (vet[y] > vet[y + 1]) { 
				aux = vet[y]; 
				vet[y] = vet[y + 1]; 
				vet[y + 1] = aux;
				
			} 
	
		}
	
	}
	System.out.println(""); 
	System.out.println("Vetor organizado:"); 
		for(x = 0; x<vet.length; x++){
			System.out.print(" "+vet[x]);
		}
	System.out.println(""); 
	System.out.println("Numero de trocas: \n"+cont); 
	}
}