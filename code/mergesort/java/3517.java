package src;

public class Mergesort implements Sortable {
	

	@Override
	public void sort(int[] array) {
		int[] tmp = new int[array.length];
		mergeSort(array, tmp,  0,  array.length - 1);
	}
	
	private static void mergeSort(int[] array, int[] tmp, int left, int right) {
		if(left < right) {
			int center = (left + right) / 2;
			mergeSort(array, tmp, left, center);
			mergeSort(array, tmp, center + 1, right);
			merge(array, tmp, left, center + 1, right);
		}
		
	}
	
	private static void merge(int[] array, int[] tmp, int left, int right, int rightEnd) {
		int leftEnd = right - 1;
		int k = left;
		int num = rightEnd - left + 1;
		
		while(left <= leftEnd && right <= rightEnd)
			if(array[left] <= (array[right]))
				tmp[k++] = array[left++];
			else
				tmp[k++] = array[right++];
		
		while(left <= leftEnd)
			tmp[k++] = array[left++];
		
		while(right <= rightEnd)
			tmp[k++] = array[right++];
			
		for(int i = 0; i < num; i++, rightEnd--)
			array[rightEnd] = tmp[rightEnd];
	}
}

