package Sorting;

// Average Case: Linearithmic. Not stable! In-place.
// Use when: Implement based on situation.

import java.util.Arrays;

public class Quicksort {
    public static void main(String[] args) {
        int array[] = {0, 1, 2, 3, 4, 5, 6, 7, -1, -10, 4, 100, 200, 0, 0, 0, 2};
        quickSort(array, 0, array.length - 1);
        System.out.println(Arrays.toString(array));
    }

    /*private static void quickSort(int[] arr, int left, int right) {
        int index = partition(arr, left, right);

        if (left < index - 1) {
            quickSort(arr, left, index - 1);
        }
        if (index < right) {
            quickSort(arr, index, right);
        }
    }*/

    private static void quickSort(int[] arr, int left, int right) {
        int index = partition(arr, left, right);

        if (left < index - 1) {
            quickSort(arr, left, index - 1);
        }

        if (index < right) {
            quickSort(arr, index, right);
        }
    }

    private static int partition(int[] arr, int left, int right) {
        int i = left, j = right;
        int temp;
        int pivot = arr[(left + right) / 2];

        while (i <= j) {
            while (arr[i] < pivot) {
                i++;
            }
            while (arr[j] > pivot) {
                j--;
            }
            if (i <= j) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
                i++;
                j--;
            }
        }
        return i;
    }
}