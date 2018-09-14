#include <iostream>
#include <algorithm>

void bubbleSort(int* const arr, int length)
{
	int iter_end(0);
	for (int i = length-1; i > 0; --i)
	{
		bool isswap = false;
		for(int j = 0; j < i; ++j)
		{
			if (arr[j] > arr[j+1])
			{
				std::swap(arr[j],arr[j+1]);
				isswap = true;
			}
		}
		iter_end++;
		if (!isswap)
		{
			std::cout << "Early termination on iteration: " << iter_end << '\n';
			break;
		}
	}
}

int main()
{
	int length;
	std::cout << "Enter size of the array: " << '\n';
	std::cin >> length;
	
	int arr[length];

	std::cout << "Enter array elements: " << '\n';
	for (int i = 0; i < length; ++i)
	{
		std::cin >> arr[i];
	}

	bubbleSort(arr, length);

	for (int i =0; i< length; ++i)
		std::cout << arr[i] << " ";
	std:: cout << '\n';
	return 0;
}
