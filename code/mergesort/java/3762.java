package main.java;

public class Mergesort {
	/**
	 * This method does the merging of arrays in the merge sort.
	 *
	 * @param data - data array we are sorting.
	 * @param lo - low boundary
	 * @param hi - high boundary
	 */
	public void merge(int arr[], int l, int m, int r) {
		int len1 = m - l + 1;
		int len2 = r - m;
		int left[] = new int[len1];
		int right[] = new int[len2];
		System.out.println("Split original array into left and right array" +
		" with size " + len1 + " and " + len2 + " respectively.");
		for (int i = 0; i < len1; ++i) {
			left[i] = arr[l + i];
		}
		System.out.print("Left array: ");
		printArr(left);
		for (int j = 0; j < len2; ++j) {
			right[j] = arr[m + 1 + j];
		}
		System.out.print("Right array: ");
		printArr(right);
		int i = 0, j = 0;
		int k = l;
		while (i < len1 && j < len2) {
			if (left[i] <= right[j]) {
				arr[k] = left[i];
				i++;
			} else {
				arr[k] = right[j];
				j++;
			}
			k++;
		}
		while (i < len1) {
			arr[k] = left[i];
			i++;
			k++;
		}
		while (j < len2) {
			arr[k] = right[j];
			j++;
			k++;
		}
		System.out.print("Merge back the left and right array: ");
		printArr(arr);
		System.out.println("");
	}

	/**
	 * The sort method which does the recursive work and actual merge sort.
	 * 
	 * @param arr - unsorted array.
	 * @param l - left boundary of the array.
	 * @param r - right boundary of the array.
	 */
	public void sort(int arr[], int l, int r) {
		if (l < r) {
			int m = (l + r) / 2;
			sort(arr, l, m);
			sort(arr, m + 1, r);
			merge(arr, l, m, r);
		}
	}

	/**
	 * print data array we are currently sorting
	 * 
	 * @param data - array which we will print.
	 */
	public static void printArr(final int[] data) { // array format.
		System.out.print("[");
		for (int i = 0; i < data.length; i++) {
			if (i != data.length - 1) {
				System.out.print(data[i] + ", ");
			} else {
				System.out.print(data[i]);
			}
		}
		System.out.print("]");
		System.out.println("");
	}

	/**
	 * main method made to test how merge sort works
	 * 
	 * @param args - empty array
	 */
	public static void main(String[] args) {
		long start = System.currentTimeMillis();
		int arr[] = { 10, 7, 8, 9, 1, 5, 6, 4, 6, 8, 10, 5, 7, 3, 2, 6, 3};
		System.out.println("Given Array");
		printArr(arr);
		Mergesort ob = new Mergesort();
		ob.sort(arr, 0, arr.length - 1);
		System.out.println("\nSorted array");
		printArr(arr);
		long end = System.currentTimeMillis();
		System.out.println("Total runtime of program: " + (end - start) + "ms");

	}
}
