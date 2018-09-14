import java.util.Arrays;

public class Quicksort  {
  private int[] numbers;
  private int number;
  public int cComparisons = 0;
  public int cSwaps = 0;
  public long executionTime = 0;
private String order;

  public void sort(int[] values, String order) {
	  this.order = order;
	final long startTime = System.nanoTime();
    // check for empty or null array
    if (values == null || values.length == 0){
      return;
    }
    this.numbers = values;
    number = values.length;
    quicksort(0, number - 1);
    executionTime = (System.nanoTime() - startTime) / 1000000;
  }
  
  public void print(){
	  System.out.println("Quicksort " + this.order + ": aantal vergelijkingen (" + this.cComparisons + "), aantal swaps (" + this.cSwaps + "), uitvoertijd (" + this.executionTime  + "ms)");
	  //System.out.println(Arrays.toString(this.numbers));
	  System.out.println();
  }

  private void quicksort(int low, int high) {
    int i = low, j = high;
    // Get the pivot element from the middle of the list
    //int pivot = numbers[low + (high-low)/2];
    int pivot = numbers[low];

    // Divide into two lists
    while (i <= j) {
      // If the current value from the left list is smaller then the pivot
      // element then get the next element from the left list
      while (numbers[i] < pivot) {
        i++;
        this.cComparisons++;
      }
      // If the current value from the right list is larger then the pivot
      // element then get the next element from the right list
      while (numbers[j] > pivot) {
        j--;
        this.cComparisons++;
      }

      // If we have found a values in the left list which is larger then
      // the pivot element and if we have found a value in the right list
      // which is smaller then the pivot element then we exchange the
      // values.
      // As we are done we can increase i and j
      if (i <= j) {
        exchange(i, j);
        i++;
        j--;
      }
    }
    // Recursion
    if (low < j)
      quicksort(low, j);
    if (i < high)
      quicksort(i, high);
  }

  private void exchange(int i, int j) {
    int temp = numbers[i];
    numbers[i] = numbers[j];
    numbers[j] = temp;
    this.cSwaps++;
  }
} 
