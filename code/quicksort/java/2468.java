package arrays;

import edu.princeton.cs.algs4.StdIn;
import edu.princeton.cs.algs4.StdRandom;

/**
 * Created by Ravikanth on 4/1/2018.
 */
public class Quicksort {


    private static void swap(int[] a, int l, int m){
        int temp = a[l];
        a[l] = a[m];
        a[m] = temp;
    }

    public static int partition(int[] a, int lo, int hi){
        int pivot = a[lo];
        int j = lo;
        for (int i = lo + 1 ; i <= hi; i++) {
            if (a[i] < pivot){
                swap(a, i, ++j);
            }
        }
        swap(a, j, lo);
        return j;
    }

    public static void sort(int[] a){
        //sort(a, 0, a.length - 1);
        q_sort3way(a, 0, a.length - 1);
    }


    private static void q_sort3way(int[] a, int lo, int hi){
        if (lo >= hi) return;
        int i = lo + 1, l = lo, m = hi;
        int pivot = a[lo];
        int cmp;
        while (i <= m){
            cmp = Integer.compare(a[i], pivot);
            if (cmp == 0){
                i++;
            }else if (cmp < 0){
                Util.swap(a, i++, l++);
            }else {
                Util.swap(a, i, m--);
            }
        }

        q_sort3way(a, lo, l - 1);
        q_sort3way(a, m + 1, hi);
    }


    private static void sort(int[] a, int lo, int hi){
        if (lo >= hi) return;

        int p = partition(a, lo, hi);
        sort(a, lo, p - 1);
        sort(a, p + 1, hi);
    }

    public static void main(String[] args) {
        int j = StdIn.readInt();
        int N = StdRandom.uniform(j);
        int[] a = new int[N];
        for (int i = 0; i < a.length; i++) {
            a[i] = StdRandom.uniform(5*j);
        }
        System.out.println("Is sorted " + Util.isSorted(a));
        System.out.println(Util.print(a));

        sort(a);
        System.out.println("Is sorted " + Util.isSorted(a));
        System.out.println(Util.print(a));
    }


    public int partitionGlobal(int[] a, int lo, int hi){
        if (a == null ) return -1;
        if (lo == hi) return lo;

        int pivot = a[lo];

        int i = lo;

        for (int j = lo + 1; j <= hi ; j++) {
            if (a[j] < pivot){
                Util.swap(a, ++i, j);
            }
        }

        swap(a, lo, i);

        return i;
    }


}
