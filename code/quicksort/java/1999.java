package sortAndSearch;

import java.text.MessageFormat;
import java.util.Arrays;
import java.util.Random;

/**
 * This class demonstrates the quicksort algorithm.
 * 
 * @author Curt Clifton
 */
public class Quicksort {
	private static final Random RAND = new Random();
	private static final int LARGEST_RANDOM_INTEGER = 1000; //Integer.MAX_VALUE;

	/**
	 * Starts the example.
	 * 
	 * @param args
	 *            not used
	 */
	public static void main(String[] args) {
		System.out.println("Testing quicksort:");
		int n = 80000;

		Integer[] array = randomArray(n);
		StopWatch timer = new StopWatch();

		timer.start();
		quicksort(array);
		timer.stop();

		ExamplesTests.assertIsSorted(array);
		
		if (n < 30) {
			System.out.println(Arrays.toString(array));
		}
		System.out.println(MessageFormat.format(
				"Sorted {0} elements in {1} ms.", n, timer.getElapsedTime()));
	}

	/**
	 * Sorts the given array in place.
	 * 
	 * @param <E>
	 *            the type of elements in the array, which must be comparable to
	 *            elements of the same type
	 * @param array
	 *            the array to be sorted
	 */
	public static <E extends Comparable<E>> void quicksort(E[] array) {
		final int n = array.length;
		// Uses a recursive helper method to avoid making copies of the array.
		qsHelper(array, 0, n);
	}

	/**
	 * Applies the quicksort algorithm to the elements array[start]..
	 * array[end-1].
	 * 
	 * @param <E>
	 *            the type of elements in the array, which must be comparable to
	 *            elements of the same type
	 * @param array
	 *            the array to be sorted
	 * @param start
	 * @param end
	 */
	private static <E extends Comparable<E>> void qsHelper(E[] array,
			int start, int end) {
		if (start + 1 >= end)
			return;

		int p = partition(array, start, end);

		qsHelper(array, start, p);
		qsHelper(array, p, end);
	}

	/**
	 * Partitions the given array into two parts and returns the pivot index.
	 * The elements of the array from array[start..end-1] are shuffled so that
	 * the elements from array[start..pivotIndex-1] are all less than or equal
	 * to array[pivotIndex] and the elements from array[pivotIndex..end-1] are
	 * all greater than or equal to array[pivotIndex].
	 * 
	 * @param <E>
	 *            the type of elements in the array, which must be comparable to
	 *            elements of the same type
	 * @param array
	 *            the array to be sorted
	 * @param start
	 * @param end
	 * @return the pivot index
	 */
	private static <E extends Comparable<E>> int partition(E[] array,
			int start, int end) {
		E pivot = array[RAND.nextInt(end - start) + start];
		int lowerIndex = start - 1;
		int upperIndex = end;
		while (lowerIndex < upperIndex) {
			// moves lowerIndex past all values less than the pivot
			lowerIndex++;
			while (array[lowerIndex].compareTo(pivot) < 0)
				lowerIndex++;
			// moves upperIndex past all values greater than the pivot
			upperIndex--;
			while (array[upperIndex].compareTo(pivot) > 0)
				upperIndex--;
			/*
			 * Unless lower and upper index have "met in the middle", both of
			 * them point to values that are on the wrong side of the pivot. So
			 * swap them.
			 */
			if (lowerIndex < upperIndex) {
				E temp = array[lowerIndex];
				array[lowerIndex] = array[upperIndex];
				array[upperIndex] = temp;
			}
		}
		return upperIndex + 1;
	}

	/**
	 * @param n
	 * @return an array of size n filled with randomly generated numbers
	 */
	private static Integer[] randomArray(int n) {
		Integer[] result = new Integer[n];
		for (int i = 0; i < n; i++) {
			result[i] = Integer
					.valueOf((int) (Math.random() * LARGEST_RANDOM_INTEGER));
		}
		return result;
	}

}
