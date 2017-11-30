package com.iokays.app;

import java.util.Random;

/**
 * Created by andy on 14-1-21.
 */
public class Quicksort {

    private static final Random RND = new Random();

    private static void swap(Object[] array, int i, int j) {        //交换
        Object tmp = array[i];
        array[i] = array[j];
        array[j] = tmp;
    }

    private static <E extends Comparable<? super E>> int partition(E[]input, int begin, int end) {
        int index = begin + RND.nextInt(end - begin + 1);       //在[begin, end]闭区间生成一个随机数作为基准
        E pivot = input[index];

        swap(input, index, end);                                //基准值与最后一个值交换

        for (int i = index = begin; i < end; ++i) {
            if (0 < pivot.compareTo(input[i])) {                //将大于基准的值放到数组的前面,begin为起点.
                swap(input, index++, i);
            }
        }

        swap(input, index, end);                                //[begin, index)都小于基准值,故交换之.
        return index;
    }

    private static <E extends Comparable<? super E>> void qsort(E[]input, int left, int right) {
       if (left < right) {
           int index = partition(input, left, right);
           qsort(input, left, index - 1);
           qsort(input, index + 1, right);
       }
    }

    public static <E extends Comparable<? super E>> void sort(E[]input) {
        qsort(input, 0, input.length - 1);
    }
}
