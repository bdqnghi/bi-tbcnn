package com.dominicwong.sort;

import com.sun.scenario.effect.Merge;

/**
 * Created by dominicwong on 4/2/15.
 */
public class MergeSort {
    public static void sort(int[] toBeSorted) {
        int[] tmp = new int[toBeSorted.length];
        MergeSort.sort(toBeSorted, tmp, 0, toBeSorted.length - 1);
    }

    private static void sort(int[] toBeSorted, int[] tmp, int start, int end) {
        if (end > start) {
            int mid = (end + start) / 2;
            MergeSort.sort(toBeSorted, tmp, start, mid);
            MergeSort.sort(toBeSorted, tmp, mid + 1, end);
            MergeSort.merge(toBeSorted, tmp, start, mid + 1, end);
        }
    }

    public static void merge(int[] toBeSorted, int[] tmp, int left, int right, int rightEnd) {
        int leftEnd = right - 1;
        int k = left;
        int length = rightEnd - left + 1;

        while (left <= leftEnd && right <= rightEnd) {
            if (toBeSorted[left] <= toBeSorted[right]) {
                tmp[k++] = toBeSorted[left++];
            } else {
                tmp[k++] = toBeSorted[right++];
            }
        }

        while (left <= leftEnd) {
            tmp[k++] = toBeSorted[left++];
        }

        while (right <= rightEnd) {
            tmp[k++] = toBeSorted[right++];
        }

        for (int i = 0; i < length; i++, rightEnd--) {
            toBeSorted[rightEnd] = tmp[rightEnd];
        }

    }
}
