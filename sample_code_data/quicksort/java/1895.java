package sorting;

/**
 * Created by cary on 5/21/17.
 */
public class Quicksort {

    private Quicksort() {

    }

    /**
     * Sort an array using an in-place QuickSort
     * <p>
     * Instructions:
     * 1.) Put pivot at the beginning
     * 2.) Run from the beginning until you find a number that's greater than the pivot
     * 3.) Run from the end backward until you find a number that's less than the pivot
     * 4.) Swap those values, continue from step 2
     * 5.) If during this process the indices meet each other, place the pivot at the point where they meet and recurse
     *
     * @param array The array to sort
     */
    public static void quicksortInPlace(int[] array, int start, int end) {
        if (end <= start) {
            return;
        } else if (end - start == 1) {
            if (array[end] < array[start]) {
                swap(array, start, end);
            }

            return;
        }

        int pivotIndex = ((end - start) / 2) + start; // Just pick the middle element for now
        int pivotValue = array[pivotIndex];
        int i = start + 1;
        int j = end;

        swap(array, start, pivotIndex); // Place the pivot at the beginning of the array

        while (i != j) {
            if (array[j] >= pivotValue) {
                j--;
                continue;
            }

            if (array[i] < pivotValue) {
                i++;
                continue;
            }

            swap(array, i, j);
        }

        if (array[start] >= array[i]) {
            swap(array, start, i);
        }
        quicksortInPlace(array, start, i - 1);
        quicksortInPlace(array, i + 1, end);
    }

    /**
     * Quicksort that uses a partition method, this is a proper QS implementation
     *
     * @param array The array to sort
     * @param start The beginning of the array
     * @param end   The end of the array
     */
    public static void quickSortPartition(int[] array, int start, int end) {
        if (start >= end) {
            return;
        }

        int pivot = array[(end + start) / 2];
        int index = partition(array, start, end, pivot);
        quickSortPartition(array, start, index - 1);
        quickSortPartition(array, index, end);
    }

    /**
     * Partition an array around a pivot
     *
     * @param array The array to partition
     * @param start The beginning of the array
     * @param end   The end of the array
     * @param pivot The pivot around which to partition
     * @return The index of the pivot after the array has been partitioned
     */
    public static int partition(int[] array, int start, int end, int pivot) {
        while (start <= end) {
            while (array[start] < pivot) {
                start++;
            }

            while (array[end] > pivot) {
                end--;
            }

            if (start <= end) {
                swap(array, start, end);
                start++;
                end--;
            }
        }

        return start;
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
