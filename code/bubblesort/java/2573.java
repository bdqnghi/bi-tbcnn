import java.util.List;
import java.util.Arrays;

public class Bubblesort {

  public static void main(String[]args) { 

    int[] unsorted = { 10,9,8,7,6,5,4,3,2,1 };
    int size = unsorted.length-1;

    final int[] sorted = bubbleSort(unsorted,size);

    for(int i: sorted) {
      System.out.print(i + ",");
    }
  }

  // 10,9,8,7,6,5,4,3,2,1
  public static int[] bubbleSort(int[] numbers, int n) {


    // while list is not sorted (if swapped is true)
    while(true) {

      boolean swapped = false;

      for(int i=0; i < numbers.length-1; i++) {

        if(numbers[i] > numbers [i+1]) {
          numbers = swap(numbers,i,i+1);
          swapped = true;
        }

      }

      if(swapped == false) {
        break;
      }
    }

    return numbers;

  }

  public static int[] swap(int[]list, int indexA, int indexB) {

    int temp = list[indexB];

    list[indexB] = list[indexA];
    list[indexA] = temp;

    return list;


  }

}
