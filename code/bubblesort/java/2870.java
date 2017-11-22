package sorting.simpleSorting;

import sorting.SortingImpl;

/**
 * The bubble sort algorithm pushes big elements to the right or small elements to 
 * the left by exchanging adjacent elements. The algorithm must sort the elements from 
 * leftIndex to rightIndex (inclusive). 
 */
public class Bubblesort<T extends Comparable<T>> extends SortingImpl<T> {

	@Override
	protected void sort(T[] array, int leftIndex, int rightIndex) {
		
		if (array.length > 1) {
			
			T aux = array[leftIndex];
			
			for (int i = leftIndex; i < rightIndex; i++) {
				for (int j = leftIndex; j < rightIndex; j++) {
					
					if (array[j].compareTo(array[j+1]) > 0) {
						aux = array[j];
						array[j] = array[j+1];
						array[j+1] = aux;
					}
					
				}
			}
		}
		
	}

}
