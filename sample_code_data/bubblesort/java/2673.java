class BubbleSort {

/**
*   BubbleSort
*   Runtime: O(n²)
*
*   Elements are sorted by comapring and swapping adjacent elements
*   for several iterations.
*
*   Pros:
*   - Easiest to implement
*   Cons:
*   - Not efficient for large inputs
*/

  static bubbleSort(int input[]) {
    // swappedCurrent keeps track of swaps in each given element
    // iteration and returns early if array is sorted.
    bool swappedCurrent;
    // length-1 because we compare two adjacent elements at a time.
    for (i = 0; i < input.length-1; i++) {
      swappedCurrent = false;
      // i-1 because last iteration for an element will be 'swap'-less.
      for (j = 0; j < i-1; j++) {
        if (input[j] > input[j+1]) {
          holder = input[j];  // ~swap
          input[j] = input[j+1];
          input[j+1] = holder;
          swappedCurrent = true;
        }
      }
      if (!swappedCurrent){
        return input;
      }
    }
    return null;
  }

}
