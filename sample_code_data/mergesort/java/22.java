package com.example;

import java.lang.annotation.Target;
import java.util.Arrays;
import java.util.Scanner;

public class Main {

    private static int[] merge(int[] left, int[] right) {
        int i = 0, j = 0;
        int[] merged = new int[left.length+right.length];
        int k = 0;
        while (i < left.length && j < right.length) {
            if (left[i] <= right[j])
                merged[k] = left[i++];
            else
                merged[k] = right[j++];
            k++;
        }

        if (i < left.length) {
            while (i < left.length) {
                merged[k++] = left[i++];
            }
        }else {
            while (j < right.length) {
                merged[k++] = right[j++];
            }
        }

        return merged;
    }

    private static int[] mergeSort(int[] ar) {
        if (ar.length <= 1)
            return ar;

        // Split the array into two halves
        int mid = ar.length / 2;
        int[] left = Arrays.copyOfRange(ar, 0 , mid);
        int[] right = Arrays.copyOfRange(ar, mid, ar.length);
        // Sort the first half
        int[] sortedLeft = mergeSort(left);
        // Sort the second half
        int[] sortedRight = mergeSort(right);
        // Merge
        int[] merged = merge(sortedLeft, sortedRight);
        return merged;
    }

    public static void main(String[] args) {
        int[] ar = {18, 6, 9, 1, 4, 15, 12, 5, 6, 7, 11};
        int[] result = mergeSort(ar);
        printArray(result);
    }

    private static void printArray(int[] ar) {
        for(int n: ar){
            System.out.print(n+" ");
        }
        System.out.println("");
    }
}
