package sorting.simpleSorting;

import sorting.SortingImpl;
import sorting.Util;

public class Bubblesort<T extends Comparable<T>> extends SortingImpl<T> {

	@Override
	protected void sort(T[] array, int leftIndex, int rightIndex) {
		
		for (int i = leftIndex; i <= rightIndex; i++) {
			
			for (int j = leftIndex; j < (rightIndex - i); j++) {
				
				if (array[j].compareTo(array[j+1]) > 0){
					
					Util.swap(array, j, j+1);
				}
			}
		}
	}
}
