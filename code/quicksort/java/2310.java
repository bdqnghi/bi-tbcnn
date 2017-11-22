package sorting;

import util.Util;

public class Quicksort {

	public static void sort(int[] array) {
		quicksort(array, 0, array.length - 1);
	}

	private static void quicksort(int[] A, int lo, int hi) {
		System.out.println("Sorting from index: " + lo + " to index: " + hi);
		if (lo < hi) {
			int p = partition(A, lo, hi);
			quicksort(A, lo, p);
			quicksort(A, p + 1, hi);
		}

	}

	private static int partition(int[] A, int lo, int hi) {

		int pivot = A[lo];
		System.out.println("Partitioning from index: " + lo + " to index: " + hi + ", pivot value: " + pivot);
		int i = lo - 1;
		int j = hi + 1;
		while (true) {

			do {
				i = i + 1;
				System.out.println("i: " + i);
			} while (A[i] < pivot);

			do {
				j = j - 1;
				System.out.println("j: " + j);
			} while (A[j] > pivot);

			if (i < j) {
				System.out.println("i < j, so switch their values.");
				Util.printArrayEmphasized(A, new int[] { i, j });
				int temp = A[i];
				A[i] = A[j];
				A[j] = temp;
				Util.printArrayEmphasized(A, new int[] { i, j });
			} else {
				System.out.println("Returning partition index j: " + j);
				return j;
			}
		}
	}

}
