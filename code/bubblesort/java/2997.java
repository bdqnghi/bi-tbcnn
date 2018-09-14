class BubbleSort {
  public static void main(String a[]) {
    int n, c, d, swap;    
     System.out.println("Input number of integers to sort");
    n = Integer.parseInt(a[0]);
     int array[] = new int[n];
    System.out.println("Enter " + n + " integers");
     for (c = 0; c < n; c++)
       array[c] = Integer.parseInt(a[c+1]);
     for (c = 0; c < ( n - 1 ); c++) {
      for (d = 0; d < n - c - 1; d++) {
        if (array[d] > array[d+1])        {
          swap       = array[d];
          array[d]   = array[d+1];
          array[d+1] = swap;
        }
      }
    }
     System.out.println("Sorted list of numbers");
     for (c = 0; c < n; c++) 
      System.out.println(array[c]);
  }
}
