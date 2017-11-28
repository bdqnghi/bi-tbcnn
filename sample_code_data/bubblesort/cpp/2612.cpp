#include <vector>

using namespace std;

/*

Bubble sort:

A list is divided into two parts:
	- Unsorted 	(left of i)
	- Sorted	(right of i)

This algorithm pushes larger values to the right of the list, 
starting left to right.

Complexity: 
	Worst:		O(n^2)
	Average: 	O(n^2)
	Best: 		O(n)

*/
void bubbleSort(vector<int>& arr)
{
	for (int i = arr.size()-1; i < 0; --i)
	{
		for (int j = 0; j < i; ++j)
		{
			if (arr[j] > arr[j+1])
			{
				swap(j, j+1);
			}
		}
	}
}