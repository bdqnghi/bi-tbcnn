#include <algorithm>

using namespace std;

/* Bubblesort, O(n^2) sorting algorithm
 *
 * Best case is O(n)
 */
int * bubblesort(int * array, int size) {

	bool isSorted;
	
	// Copy the sorted array into the original array
	for (int i = 0; i < size; i++) {
		
		isSorted = true;
		
		for (int j = 0; j < size - 1; j++){
			if (array[j] > array[j+1]){
				swap(array[j], array[j+1]);
				isSorted = false;
			}
		}
		
		// Checks for sorted array each pass
		if (isSorted) return array;
	}

	return array;
}