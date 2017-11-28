package recursiveSortingPackage;
// implementation of pseudocode on 
// http://en.wikipedia.org/wiki/Quicksort
// hau

public class Quicksort {

    public static void quicksort(int[] array, int left, int right) {

        // If the list has 2 or more items
        if (left < right) {
            // Get lists of bigger and smaller items and final position of pivot
            int pIndex = partition(array, left, right);

            // Recursively sort elements smaller than the pivot
            quicksort(array, left, pIndex - 1);

            // Recursively sort elements at least as big as the pivot
            quicksort(array, pIndex + 1, right);
        }
    }
    
    // left is the index of the leftmost element of the array
    // right is the index of the rightmost element of the array (inclusive)
    // number of elements in subarray = right-left+1
    private static int partition(int[] array, int left, int right) {
        // choose any 'pivotIndex' such that 'left' ≤ 'pivotIndex' ≤ 'right'
        int pivotIndex = (right + left) / 2;
        int pivotValue = array[pivotIndex];

        swap(array, pivotIndex, right);

        int storeIndex = left;

        //for 'i' from 'left' to 'right' - 1  // left ≤ i < right
        for (int i = left; i < right; i++) {
            if (array[i] < pivotValue) {
                swap(array, i, storeIndex);
                storeIndex = storeIndex + 1;
            }
        }
        swap(array, storeIndex, right);

        return storeIndex;
    }

    private static void swap(int[] array, int i, int j) {
        //swap array[i] and array[j]
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
 
}
