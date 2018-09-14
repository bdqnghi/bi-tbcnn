package org.colfax.org.colfax.interview_prep;

/**
 * Created by colfax on 11/17/2014.
 */
public class Mergesort {
    /**
     * "Marge"sort.
     * Recurse until there's only one element.
     * Copy range to a tmp array.
     * Merge. L->M, and M+1->R. Copying smaller back to original array.
     * Copy LHS leftovers back to original
     */
    public void mergesort(int[] A){
        int[] tmp = new int[A.length];
        mergesort(A, tmp, 0, A.length-1);
    }

    private void mergesort(int[] A, int[] tmp, int L, int R){
        if(L < R){
            int m = (L+R)/2;
            mergesort(A, tmp, L, m);
            mergesort(A, tmp, m+1, R);
            merge(A, tmp, L, m, R);
        }
    }

    private void merge(int[] A, int[] tmp, int L, int m, int R){
        for(int i = L; i <= R; i++)
            tmp[i] = A[i];

        // Helper pointers...
        int hL   = L;
        int hR   = m+1;
        int curr = L;

        // Compare and copy
        while(hL <= m && hR <= R) {
            if(tmp[hL] < tmp[hR]) {
                A[curr] = tmp[hL];
                hL++;
            }
            else{
                A[curr] = tmp[hR];
                hR++;
            }
            curr++;
        }

        // Copy over any remaining items from the left side.
        int rem = m - hL;
        for(int i = 0; i <= rem; i++)
            A[curr + i] = tmp[hL + i];
    }

    public static void main(String[] args){
        int[] arr = {6, 5, 3, 7, 8, 2, -23, 53, 66, 72, 12, 30, 123, -100000000, 423525216};
        Mergesort ms = new Mergesort();
        ms.mergesort(arr);
        for(int i : arr)
            System.out.print(i + ", ");
    }
}
