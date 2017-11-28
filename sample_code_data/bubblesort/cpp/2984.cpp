// Bubble Sort:
// Time Complexity: Best: O(n), Average: O(n^2), Worst: O(n^2)
// Space Complexity: Worst: O(1)
// 1 + 2 + 3 + . . . + (n - 1) = n(n - 1)/2 = O(n^2)

#include <algorithm>
#include <iostream>
#include <iterator>
 
template <typename RandomAccessIterator>
void bubble_sort(RandomAccessIterator begin, RandomAccessIterator end) {
	bool swapped = true;
	while (begin != end-- && swapped) {
		swapped = false;
		for (auto i = begin; i != end; ++i) {
			if (*(i + 1) < *i) {
				std::iter_swap(i, i + 1);
				swapped = true;
			}
		}
	}
}
 
int main() {
	int a[] = {100, 2, 56, 200, -52, 3, 99, 33, 177, -199};
	bubble_sort(std::begin(a), std::end(a));
	copy(std::begin(a), std::end(a), std::ostream_iterator<int>(std::cout, " "));
	std::cout << "\n";
}

/*
The only significant advantage that bubble sort has over most other implementations, even quicksort, but not insertion sort, is that the ability to detect that the list is sorted efficiently is built into the algorithm. When the list is already sorted (best-case), the complexity of bubble sort is only O(n). By contrast, most other algorithms, even those with better average-case complexity, perform their entire sorting process on the set and thus are more complex. However, not only does insertion sort have this mechanism too, but it also performs better on a list that is substantially sorted (having a small number of inversions).

The algorithm for bubble sort requires a pair of nested loops. The outer loop must iterate once for each element in the data set (of size n) while the inner loop iterates n times the first time it is entered, n-1 times the second, and so on. Consider the purpose of each loop. As explained above, bubble sort is structured so that on each pass through the list the next largest element of the data is moved to its proper place. Therefore, to get all n elements in their correct places, the outer loop must be executed n times.

The inner loop is executed on each iteration of the outer loop. Its purpose is to put the next largest element is being put into place. The inner loop therefore does the comparing and swapping of adjacent elements. To determine the complexity of this loop, we calculate the number of comparisons that have to be made. On the first iteration of the outer loop, while trying to place the largest element, there have to be n - 1 comparisons: the first comparison is made between the first and second elements, the second is made between the second and third elements, and so on until the n-1th comparison is made between the n-1th and the nth element. On the second iteration of the outer loop, there is no need to compare the against the last element of the list, because it was put in the correct place on the previous pass. Therefore, the second iteration requires only n-2 comparisons. This pattern continues until the second-to-last iteration of the outer loop when only the first two elements of the list are unsorted; clearly in this case, only one comparison is necessary. The total number of comparisons, therefore, is (n - 1) + (n - 2)...(2) + (1) = n(n - 1)/2 or O(n^2).
*/



void bubbleSort(int numbers[], int array_size)
{
	int i, j, temp;

	for (i = (array_size - 1); i >= 0; i--)
	{
		for (j = 1; j <= i; j++)
		{
			if (numbers[j-1] > numbers[j])
			{
				temp = numbers[j-1];
				numbers[j-1] = numbers[j];
				numbers[j] = temp;
			}
		}
	}
}

/*
PARALLEL BUBBLE SORT (A) 

For k = 0 to n-2 
If k is even then
	for i = 0 to (n/2)-1 do in parallel 
		If A[2i] > A[2i+1] then
			Exchange A[2i] ↔ A[2i+1] 
Else
	for i = 0 to (n/2)-2 do in parallel 
		If A[2i+1] > A[2i+2] then 
			Exchange A[2i+1] ↔ A[2i+2]
Next k 
 

Parallel Analysis 
Steps 1-10 is a one big loop that is represented n -1 times. Therefore, the parallel time complexity is O(n). If the algorithm, odd-numbered steps need (n/2) - 2 processors and even-numbered steps require (n/2) - 1 processors. Therefore, this needs O(n) processors.
*/


/*
PROOF OF O(n^2)

The average of 11 and n−1n−1 is n2n2.

The average of 22 and n−2n−2 is n2n2.

The average of 33 and n−3n−3 is n2n2.

The average of 44 and n−4n−4 is n2n2.

and so on ……

So the average of all of them is n/2:
1+2+3+⋯+(n−1)/(n−1) = n/2

1+2+3+⋯+(n−1) = (n-1)n/2 

*/

