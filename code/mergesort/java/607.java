package sorting;

/**
 * Created by cary on 5/21/17.
 */
public class Mergesort {

    private Mergesort() {

    }

    /**
     * Sort an array using mergesort
     *
     * @param array The array to sort
     */
    public static void mergesort(int[] array) {
        mergesort(array, new int[array.length], 0, array.length - 1);
    }

    /**
     * Mergesort using a temporary buffer
     *
     * @param array The array to sort
     * @param temp  The buffer array (should be at least as large as array)
     * @param start The beginning position to sort
     * @param end   The end position to sort
     */
    private static void mergesort(int[] array, int[] temp, int start, int end) {
        if (start >= end) {
            return;
        }

        if (end - start == 1 && array[start] > array[end]) {
            swap(array, start, end);
            return;
        }

        int middle = (start + end) / 2;

        mergesort(array, temp, start, middle);
        mergesort(array, temp, middle + 1, end);
        merge(array, temp, start, middle, middle + 1, end);
    }

    /**
     * Merge two sorted sections of an array using a temporary buffer
     *
     * @param array      The array to sort
     * @param temp       The temporary buffer to use for sorting
     * @param leftStart  The beginning of the left section to merge
     * @param leftEnd    The end of the left section to merge
     * @param rightStart The beginning of the right section to merge
     * @param rightEnd   The end of the right section to merge
     */
    public static void merge(int[] array, int[] temp, int leftStart, int leftEnd, int rightStart, int rightEnd) {
        int size = (leftEnd - leftStart) + (rightEnd - rightStart) + 2;
        int i = leftStart, j = rightStart;
        for (int m = 0; m < size; m++) {
            if (i > leftEnd) {
                temp[m] = array[j];
                j++;
            } else if (j > rightEnd) {
                temp[m] = array[i];
                i++;
            } else if (array[i] < array[j]) {
                temp[m] = array[i];
                i++;
            } else {
                temp[m] = array[j];
                j++;
            }
        }

        for (int m = 0; m < size; m++) {
            array[m + leftStart] = temp[m];
        }
    }

    /**
     * Swap the indices i, j in a given array
     *
     * @param array The array in which to do the swapping
     * @param i     index 1
     * @param j     index 2
     */
    private static void swap(int[] array, int i, int j) {
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
}
