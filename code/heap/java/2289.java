//*******************************************************************
//  Heap.java 
//      
//  Defines the interface to a heap.
//*******************************************************************
public interface Heap<T>
{

   //  Adds the specified object to the heap. 
   public void add (T obj);

   //  Removes and returns the top element from the heap
   public T remove ();
   
  //  Returns true if the heap is empty and false otherwise
   public boolean isEmpty();

  // Returns true if the heap is full
   public boolean isFull();
   
   //  Returns the value at the top the Heap. (does not remove the value)
   public T getTop ();

   // Returns the number of values on the heap
   public int sizeOf();
   
   // Displays a diagram of the heap in level order fashion
   public void drawHeap();
   
   // Displays a sorted list of elements on the heap without destroying the heap
   public void printSorted();
   
   // Returns the heap in sorted order using the in-place heap sort algorithm
   public T[] heapSort();
   
}

