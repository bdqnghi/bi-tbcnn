package utils;

/*
 The original class is copied from http://www.vogella.com/articles/JavaAlgorithmsMergesort/article.html
 The program makes following changes:
 1. the type of array is changed from int[] to ByteArrayWrapper[]
 2. add compare();
 */

public class Mergesort {
	private ByteArrayWrapper[] numbers;
	private ByteArrayWrapper[] helper;

	private int number;

	public void sort(ByteArrayWrapper[] values) {
		this.numbers = values;
		number = values.length;
		this.helper = new ByteArrayWrapper[number];
		mergesort(0, number - 1);
	}

	private void mergesort(int low, int high) {
		// Check if low is smaller then high, if not then the array is sorted
		if (low < high) {
			// Get the index of the element which is in the middle
			int middle = (low + high) / 2;
			// Sort the left side of the array
			mergesort(low, middle);
			// Sort the right side of the array
			mergesort(middle + 1, high);
			// Combine them both
			merge(low, middle, high);
		}
	}

	private void merge(int low, int middle, int high) {

		// Copy both parts into the helper array
		for (int i = low; i <= high; i++) {
			helper[i] = numbers[i];
		}

		int i = low;
		int j = middle + 1;
		int k = low;
		// Copy the smallest values from either the left or the right side back
		// to the original array
		while (i <= middle && j <= high) {
			// if (helper[i] <= helper[j]) {
			if (compare(helper[i].data, helper[j].data) <= 0) {
				numbers[k] = helper[i];
				i++;
			} else {
				numbers[k] = helper[j];
				j++;
			}
			k++;
		}
		// Copy the rest of the left side of the array into the target array
		while (i <= middle) {
			numbers[k] = helper[i];
			k++;
			i++;
		}
	}

	public int compare(byte[] left, byte[] right) {
		for (int i = 0, j = 0; i < left.length && j < right.length; i++, j++) {
			int a = (left[i] & 0xff);
			int b = (right[j] & 0xff);
			if (a != b) {
				return a - b;
			}
		}
		return left.length - right.length;
	}
}
