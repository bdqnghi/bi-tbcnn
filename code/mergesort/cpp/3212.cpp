//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2013 __Pearson Education__. All rights reserved.

// Listing 11-4.

#include <iostream>
#include <string>

using namespace std;

/** Merges two sorted array segments theArray[first..mid] and
    theArray[mid+1..last] into one sorted array.
 @pre  first <= mid <= last. The subarrays theArray[first..mid] and
    theArray[mid+1..last] are each sorted in increasing order.
 @post  theArray[first..last] is sorted.
 @param theArray  The given array.
 @param first  The index of the beginning of the first segment in theArray.
 @param mid  The index of the end of the first segment in theArray;
    mid + 1 marks the beginning of the second segment.
 @param last  The index of the last element in the second segment in theArray.
 @note  This function merges the two subarrays into a temporary
    array and copies the result into the original array theArray. */
template<class ItemType>
void merge(ItemType theArray[], int first, int mid, int last, ItemType tempArray[])
{
   // Initialize the local indices to indicate the subarrays
   int first1 = first;            // Beginning of first subarray
   int last1 = mid;               // End of first subarray
   int first2 = mid + 1;          // Beginning of second subarray
   int last2 = last;              // End of second subarray
   
   // While both subarrays are not empty, copy the
   // smaller item into the temporary array
   int index = first1;            // Next available location in tempArray
   while ((first1 <= last1) && (first2 <= last2))
   {
      // At this point, tempArray[first..index-1] is in order
      if (theArray[first1] <= theArray[first2])
      {
         tempArray[index] = theArray[first1];
         first1++;
      }
      else
      {
         tempArray[index] = theArray[first2];
         first2++;
      }  // end if
      index++;
   }  // end while
   
   // Finish off the first subarray, if necessary
   while (first1 <= last1)
   {
      // At this point, tempArray[first..index-1] is in order
      tempArray[index] = theArray[first1];
      first1++;
      index++;
   }  // end while
   
   // Finish off the second subarray, if necessary
   while (first2 <= last2)
   {
      // At this point, tempArray[first..index-1] is in order
      tempArray[index] = theArray[first2];
      first2++;
      index++;
   }  // end for
   
   // Copy the result back into the original array
   for (index = first; index <= last; index++)
      theArray[index] = tempArray[index];
}  // end merge

/** Sorts the items in an array into ascending order.
 @pre  theArray[first..last] is an array.
 @post  theArray[first..last] is sorted in ascending order.
 @param theArray  The given array.
 @param first  The index of the first element to consider in theArray.
 @param last  The index of the last element to consider in theArray. */
template<class ItemType>
void mergeSort(ItemType theArray[], int first, int last, ItemType tempArray[])
{
   if (first < last)
   {
      // Sort each half
      int mid = (first + last) / 2; // Index of midpoint
      
      // Sort left half theArray[first..mid]
      mergeSort(theArray, first, mid, tempArray);
      
      // Sort right half theArray[mid+1..last]
      mergeSort(theArray, mid + 1, last, tempArray);
      
      // Merge the two halves
      merge(theArray, first, mid, last, tempArray);
   }  // end if
}  // end mergeSort

template<typename ItemType>
void mergeSort(ItemType theArray[], int n)
{
	ItemType* tempArray = new ItemType[n];  // Temporary array
	mergeSort(theArray, 0, n-1, tempArray);
	delete [] tempArray;
}
