package sortingAlgorithms;

public class Mergesort {

	private int[] array;
	private int[] temp;
	private int arrayLength;

	public void sort(int[] array) {
		this.array = array;
		arrayLength = array.length;
		this.temp = new int[arrayLength];
		mergesort(0, arrayLength - 1);
	}

	private void mergesort(int first, int last) {
		if (first < last) {
			int middle = first + (last - first) / 2;

			mergesort(first, middle);
			mergesort(middle + 1, last);

			merge(first, middle, last);
		}
	}

	private void merge(int first, int middle, int last) {

		for (int i = first; i <= last; i++) {
			temp[i] = array[i];
		}

		int i = first;
		int j = middle + 1;
		int k = first;
		while (i <= middle && j <= last) {
			if (temp[i] <= temp[j]) {
				array[k] = temp[i];
				i++;
			} else {
				array[k] = temp[j];
				j++;
			}
			k++;
		}
		while (i <= middle) {
			array[k] = temp[i];
			k++;
			i++;
		}

	}
}
