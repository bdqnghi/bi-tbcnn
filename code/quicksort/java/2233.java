import java.util.*; 

class quicksort{


  public void sort(int[] arr, int beg, int end)
  {
    if(end <= beg){return;} //base case
    
    int pivot = partition(arr, beg, end); //the pivot is in final position; nothing else
    sort(arr, beg, pivot - 1); //sort left half
    sort(arr, pivot + 1, end); //sort right half
  }
  
  public int partition(int[] arr, int beg, int end)
  {

    int left = beg; 
    int right = end; 
    int pivot = arr[(beg+end)/2];
    int pivotIndex;
    while(right > left)
    {
      while(arr[right] > pivot)//will be on the right 
      { //stay there already in greater position 
        right--; 
      }
      while(arr[left] < pivot)
      { //stay there already in less than position 
        left++; 
      }
      if(left <= right)
      { //have to do = or else never cross
        swap(arr, left, right);
        left++;
        right--; 
      }

    } 
    /*|LeftPointer|pivot|RightPointer|
    ends up as 
    |RightPointer|pivot|LeftPointer|
    **/
    
    return (pivotIndex = left - 1);
  }

  public void swap(int[] arr, int a, int b)
  {
    int temp = arr[a];
    arr[a] = arr[b]; 
    arr[b] = temp; 
  }

  public static void main(String[] args)
  {
    quicksort caller = new quicksort(); 
    //non-static hence have to make an instance of the class
    int[] unorg = new int[]{2, 3, 5, 1, 0, 4, 3};
    caller.sort(unorg, 0, unorg.length-1);
    for(int num : unorg)
      System.out.println(num);
  }
}
