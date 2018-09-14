#include <iostream>

using namespace std;

int main()
{
	double arr[] = {2.5, .7, 2, 1.2, 5, 1, .2};
	int iLength = 7;

	// Output the unsorted array
	cout << "Initial Array: ";
	for (int iIndex = 0; iIndex < iLength; ++iIndex)
	{
		cout << arr[iIndex] << " ";
	}
	cout << endl;

	//The Bubblesort

	for (int iEnd = iLength - 1; iEnd > 0; --iEnd)
	{
		cout << "iEnd is: " << iEnd << endl;
		for (int iIndex = 0; iIndex < iEnd; ++iIndex)
		{
			//cout << "arr[iIndex] is: " << arr[iIndex] << " ";
			//Check if the elements are out of order and swap them, if needed.
		if (arr[iIndex] > arr[iIndex + 1])
		{
			double dTemp = arr[iIndex];
			arr[iIndex] = arr[iIndex + 1];
			arr[iIndex + 1] = dTemp;
		}	
		}
	}

	// Output the sorted array
	cout << "Sorted Array: ";
	for (int iIndex =0; iIndex < iLength; ++iIndex)
	{
		cout << arr[iIndex] << " ";
	}
	cout << endl;

	system("pause");

	return 0;
}