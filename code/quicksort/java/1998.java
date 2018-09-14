package quickSort;
//ZAGE STRASSBERG-PHILLIPS
//APCS, PERIOD 4

public class Quicksort {
	
	/* This function takes last element as pivot,
    places the pivot element at its correct
    position in sorted array, and places all
    smaller (smaller than pivot) to left of
    pivot and all greater elements to right
    of pivot */
public static int partition(int arr[], int low, int high)
 {
     int pivot = arr[high]; 
     int i = (low-1); // index of smaller element
     for (int j=low; j<high; j++)
     {
         // If current element is smaller than or
         // equal to pivot
         if (arr[j] <= pivot)
         {
             i++;

             // swap arr[i] and arr[j]
             int temp = arr[i];
             arr[i] = arr[j];
             arr[j] = temp;
         }
     }

     // swap arr[i+1] and arr[high] (or pivot)
     int temp = arr[i+1];
     arr[i+1] = arr[high];
     arr[high] = temp;

     return i+1;
 }


 /* The main function that implements QuickSort()
   arr[] --> Array to be sorted,
   low  --> Starting index,
   high  --> Ending index */
 public static void sort(int arr[], int low, int high)
 {
     if (low < high)
     {
         /* pi is partitioning index, arr[pi] is 
           now at right place */
         int pi = partition(arr, low, high);

         // Recursively sort elements before
         // partition and after partition
         sort(arr, low, pi-1);
         sort(arr, pi+1, high);
     }
 }

 /* A utility function to print array of size n */
 public static void printArray(int arr[])
 {
     int n = arr.length;
     for (int i=0; i<n; ++i)
         System.out.print(arr[i]+" ");
     System.out.println();
 }
 
 /* FIND_MEDIAN METHOD 
  * This method takes and sorted array of integers.
  * Then, determines the length of the given array,
  * checking if the length is even or odd.
  * If the length is odd it returns the number
  * at the center of the array. If the length is 
  * even it find the two center values, adds them
  * together and divides by two to find the median.*/
 public static double findMedian(int arr[]) {
	 int length = arr.length;
	 if (length % 2 == 1) {
		 //System.out.println(arr[length/2]);
		 return (double)arr[length/2];
	 }
	 //System.out.println(arr[length/2-1]);
	 //System.out.println(arr[length/2]);
	 return (double)(arr[length/2-1] + arr[(length/2)])/2;
 }

 // Driver program
 public static void main(String args[])
 {
     int arr[] = {10, 7, 8, 4, 9, 1, 5};
     int n = arr.length;

//     QuickSort ob = new QuickSort();
     sort(arr, 0, n-1);

     System.out.println("sorted array");
     printArray(arr);
     
     System.out.println("median");
     System.out.println(findMedian(arr));
 }
}
/*This code is contributed by Rajat Mishra */

/* Acknowledgements:
 * I watched this video: https://www.youtube.com/watch?v=COk73cpQbFQ,
 * which helped explain what the quickSort method was/does.
 * Then I found and read the code for the quickSort method on this site:
 * https://www.geeksforgeeks.org/quick-sort/ (code is contributed by 
 * Rajat Mishra). Then I modified the code by adding the findMedian 
 * method (which as it implies, finds the median of an array).*/
	

