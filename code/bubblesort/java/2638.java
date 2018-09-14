package com.interview.prep.sorting;

public class Bubblesort {
	
	
	Bubblesort(){
		System.out.println("I am getting called");
	}
	/**
	 * PSEUDO CODE :
	 * main array, 
	 * second array
	 * if element in the next index is less swap that with the new index
	 * 
	 * @param args
	 */
	static int [] array;
	void bubblesort(){
		
		for (int i =0; i < array.length-1 ; i++){
			
			  for (int j= 0; j < array.length-1; j++){
				  
				  if(array[j+1] < array[j]){
					  swapIndexValues(j,j+1);
				  }
			   }
		    }	
	    	printArray(array);
	     }
	
	void swapIndexValues(int currentIndex, int nextIndex){
	    int temp;
		temp = array[currentIndex];
		array[currentIndex] = array[nextIndex];
		array[nextIndex] = temp;
	}

		void printArray(int [] array){
			//Print array :
			for(int arr : array){
				System.out.print(arr+" ");
			}
		}
	
	public static void main(String args[]){
		
		array = new int [11];
        array[0] = 7;
		array[1] = 1;
		array[2] = 2;
		array[3] = 5;
		array[4] = 8;
		array[5] = 15;
		array[6] = 100;
		array[7] = 45;
		array[8] = 32;
		array[9] = 4;
		array[10] = 0;
		
		Bubblesort bubblesort = new Bubblesort();
		bubblesort.printArray(array);
		bubblesort.bubblesort();
		//bubblesort.printArray(array);
	}
}


/**
 * STEPS CODE :
 * Compare each element with the next element
 * If the element and the next element is less, swap, this way the largest element will reach at the end 
 * Also this cycle should be completed in one go
 * Then next cycle does the same 
 * 
 * @param args
 */