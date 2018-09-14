//mergesort is a stable, non-inplace sorting algorithm.

package sortAlg;

public class Mergesort extends Sort_int{
	
	public Mergesort(String name){
		super(name);
	}
	public Mergesort(){
		super("Mergesort");
	}
	
	@Override 
	public void sort(int array[]){
		devide(array);
		return;
	}
	
	private static void devide(int array[]){
		
		//devide arrays in 2 parts
		int length = array.length;
		if (length == 1){return;}
		int fi = length/2;
		int la = length - fi;
		
		int array1[] = new int[fi];
		int array2[] = new int[la];
		
		//init new arrays
		for(int i = 0; i < fi; i++){
			array1[i] = array[i];
		}
		for(int i = 0; i < fi; i++){
			array2[i] = array[i+fi];
		}
		
		// devide the arrays and then conquer them
		// #DevideAndConquer
		devide(array1);
		devide(array2);
		conquer(array, array1, array2);
		
	}
	
	private static void conquer(int array[], int array1[], int array2[]){
		int i = 0,j = 0;
		int max = array.length;
		//conquer is the hard part for the cpu
		// we have to pick the smallest entry from the 2 arrays and insert it in the main array
		// i think i could improve this section here quite a bit
		while(true){
			if(i < array1.length && j < array2.length){
				if(array1[i] < array2[j]){
					array[i+j] = array1[i];
					i++;
				}
				else{
					array[i+j] = array2[j];
					j++;
				}
				if (i+j == max){
					return;
				}
			}
			else if(i < array1.length){
				array[i+j] = array1[i];
				i++;
				if (i+j == max){
					return;
				}
			}
			else {
				array[i+j] = array2[j];
				j++;
				if (i+j == max){
					return;
				}
			}
		}
	}
}
