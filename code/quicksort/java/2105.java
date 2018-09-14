public class Quicksort {

	public static void quickSort(int[] array) {
		sort(array, 0, array.length-1);
	}

	public static void sort(int[] array, int low, int high) {
		if(high > low) {
			int pivot = partition(array, low, high);
			sort(array, low, pivot-1);
			sort(array, pivot+1, high);
		}
	}

	public static int partition(int[] array, int low, int high) {
		int pivot = array[high];
		int i = low-1;
		
		for(int j = low; j < high; j++) {
			if(array[j] <= pivot) {
				i++;
				swap(array, i, j);
			}
		}

		swap(array, i+1, high);
		return i+1;
	}

	public static void swap(int[] array, int i, int j) {
		int temp = array[i];
		array[i] = array[j];
		array[j] = temp;
	}

	public static void main(String args[]) {
		int[] array = {3,5,2,5,2,4,7,9,65,2,1};
		quickSort(array);

		for(int i = 0; i < array.length; i++) {
			System.out.print(array[i] + " ");
		}
	}
}
