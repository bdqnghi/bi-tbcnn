/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package sorting;

/**
 *
 * @author bharathsurampudi
 */
public class Mergesort {

    void mergesort(int[] arr) {
        int size = arr.length;
        if (size < 2) {
            return;
        }
        int mid = size / 2;
        int[] left = new int[mid];
        int[] right = new int[size - mid];
        for (int i = 0; i < mid; i++) {
            left[i] = arr[i];
        }
        for (int i = mid; i < size; i++) {
            right[i - mid] = arr[i];
        }
        mergesort(left);
        mergesort(right);
        merge(left, right, arr);
    }

    void merge(int[] left, int[] right, int[] arr) {
        int i = 0, j = 0, k = 0;
        int ls = left.length, rs = right.length, ns = arr.length;
        while (i < ls && j < rs) {
            if (left[i] < right[j]) {
                arr[k] = left[i];
                i++;
            } else {
                arr[k] = right[j];
                j++;
            }
            k++;
        }
        while (i < ls) {
            arr[k] = left[i];
            i++;
            k++;
        }
        while (j < rs) {
            arr[k] = right[j];
            j++;
            k++;
        }

    }

    void printArray(int[] arr) {
        for (int i = 0; i < arr.length; i++) {
            System.out.print(arr[i] + " ");
        }
        System.out.println(" ");
    }

    public static void main(String[] args) {
        Mergesort ob = new Mergesort();
        int[] arr = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
        ob.printArray(arr);
        ob.mergesort(arr);
        ob.printArray(arr);
    }
}