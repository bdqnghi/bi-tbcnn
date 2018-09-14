import java.util.Scanner; 

public class mergesort {
  public void solve() { 
    //Input 
    Scanner sc = new Scanner(System.in);
    String[] input = sc.nextLine().split(" ");
    int n = input.length; 
    int[] arr = new int[n];
    for (int j = 0; j < n; j++) 
      arr[j] = Integer.parseInt(input[j]);
    //Algorithm
    arr = mergesort(arr);
    //Output 
    for (int i = 0; i < arr.length; i++) 
      System.out.println(arr[i]);
  }
  
  public int[] mergesort(int[] arr) {
    int len = arr.length; 
    if (len <= 1)
      return arr; 
    int alen = len / 2; 
    int blen = len - alen; 
    int[] a = new int[alen];
    int[] b = new int[blen]; 
    for (int i = 0; i < alen; i++) 
      a[i] = arr[i];
    for (int i = 0; i < blen; i++)
      b[i] = arr[alen + i];
    return merge(mergesort(a), mergesort(b));
  }
  
  public int[] merge(int[] a, int[] b) {
    int alen = a.length; 
    int blen = b.length; 
    int len = alen + blen; 
    int[] arr = new int[len];
    int i = 0, j = 0, k = 0; 
    while (k < len) { 
      while (i < alen && j < blen) 
        if (a[i] < b[j])  
          arr[k++] = a[i++];
        else if (a[i] > b[j]) 
          arr[k++] = b[j++];
        else { 
          arr[k++] = a[i++]; 
          arr[k++] = b[j++];
        }
        while (i < alen)  
          arr[k++] = a[i++];
        while (j < blen)
          arr[k++] = b[j++];
    }
    return arr; 
  }
  
  public void run() { 
    int[] a = {1,4,5,6,7}; 
    int[] b = {2, 3, 5, 7, 8};
    int[] arr = merge(a, b);
    
    for (int i = 0; i < arr.length; i++) 
      System.out.println(arr[i]); 
  }
  
  public static void main(String args[]) { 
    new mergesort().run(); 
  }
}
