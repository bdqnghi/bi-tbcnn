/**
 * Bubble Sort
 *  the bubble sort compares adjacent items
 *  and exchanges them if they are out of order
 *
 *  requires at most n - 1 passes
 *
 * Bubble Sort
 *  best case: O(n)
 *  average case &
 *  worst case: O(n^2)
 */

#include <iostream>
#include "helper.h"

using namespace std;

void bubbleSort(DataType theArray[], int n)
{
  bool sorted = false; // false when swap occurs

  for (int pass = 1; (pass < n) && !sorted; ++pass)
  {
    sorted = true; // assume sorted
    for (int index = 0; index < n - pass; ++index)
    {
      int nextIndex = index + 1;
      if (theArray[index] > theArray[nextIndex])
      {
        swap(theArray[index], theArray[nextIndex]);
        sorted = false; // to signal exchange
      }
    }
  }
}

int main()
{
  int myArray[] = {2, 7, 3, 18, 9};
  int myArray2[] = {2, 5, 4, 18, 9, 24, 14};
  int myArray3[] = {2, 7, 3, 18, 9, 32, 48, 14, 5};

  cout << "Initial state:" << endl;
  displayArray(myArray, 5);
  displayArray(myArray2, 7);
  displayArray(myArray3, 9);

  bubbleSort(myArray, 5);
  bubbleSort(myArray2, 7);
  bubbleSort(myArray3, 9);

  cout << "After sorting:" << endl;
  displayArray(myArray, 5);
  displayArray(myArray2, 7);
  displayArray(myArray3, 9);

  return 0;
}
