import java.io.*;
import java.util.*;

public class Quicksort {
    
    public static void Quicksort(int[] L,int left,int right) {
	if (right - left > 0) {
	    int pivotI = partition(L,left,right);
	    Quicksort(L,left,pivotI - 1);
	    Quicksort(L,pivotI + 1,right);
	}
    }

    public static void Quicksort(int[] L) {
	Quicksort(L,0,L.length-1);
    }
    
    public static void swap(int[] L,int a,int b) {
	int temp = L[a];
	L[a] = L[b];
	L[b] = temp;
    }
    public static int partition(int[] L,int left,int right) {
	Random r = new Random();
	int val = left;
	int pivotI = r.nextInt(right - left + 1) + left;
	int pivot = L[pivotI];
        swap(L,pivotI,right);
	for (int i = left; i < right; i++) {
	    if (L[i] < pivot) {
		swap(L,i,val);
		val++;
	    }
	}
	swap(L,right,val);
	return val;
    }
}
