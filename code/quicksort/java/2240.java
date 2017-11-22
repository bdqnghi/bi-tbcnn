package quicksort;


import java.util.Arrays;

/**
 * Created by umesh on 8/22/15.
 */
public class Quicksort {
    public Quicksort() {
    }

    private static void println(String str) {
        System.out.println(str);
    }

    public static void main(String[] args) {
        int[] testArray = new int[] {25, 200, 10, 300, 500, 1, 2,3};
        Quicksort qs = new Quicksort();
        qs.quicksort(testArray);
        System.out.println(Arrays.toString(testArray));
    }

    public void quicksort(int[] array) {
        quicksort(array, 0, array.length-1);
    }

    public void quicksort(int[] array, int start, int end) {
        println("quicksort arr start=" + start  + ", end=" + end);
        if(array == null || (end-start+1) < 2) {
            return;
        }
        int pivot = array[start];

        int initialJ = 0;
        for(int ij=(start+1);ij<=end;ij++) {
            if(array[ij] > pivot) {
                initialJ = ij;
                break;
            }
        }

        int j = initialJ;
        int i=j-1;

        while(j <= end) {
            if(array[j] > pivot) {
                j++;
            } else {
                swap(array, j, i+1);
                i++; j++;
            }
        }
        swap(array, 0, i);
        quicksort(array, 0, i);
        quicksort(array, i+1, end);

    }

    private void swap(int[] arr, int i, int j) {
        println("swap arr i=" + i  + ", j=" + j);
        int t = arr[i];
        arr[i] = arr[j];
        arr[j] = t;
    }


    @Override
    public String toString() {
        return "Quicksort{}";
    }
}
