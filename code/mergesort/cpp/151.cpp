// Implementing MergeSort in C++

#include <iostream>
#include <ctime>


using namespace std;

void merge(int* a, int start, int middle,int end)
{
	int len = end - start + 1;
	int* tempList = new int[len];
	for (int index = 0; index < len; index++)
	{
		tempList[index] = a[start + index];
	}
	int i = 0;
	int j = middle-start+1;
	for (int k = start; k <= end; k++)
	{

		if (i == middle - start + 1)
		{
			a[k] = tempList[j++];
			continue;
		}
		if (j == end - start + 1)
		{
			a[k] = tempList[i++];
			continue;
		}

		if (tempList[i] > tempList[j])
		{
			a[k] = tempList[j++];
		}
		else
		{
			a[k] = tempList[i++];
		}

	}
}

void mergeSort(int* a, int start, int end)
{
	if (start < end)
	{
		int middle = (start + end) / 2;
		mergeSort(a, start, middle);
		mergeSort(a, middle + 1, end);
		merge(a, start, middle, end);
	}
}
int main()
{
  int numExamples = 1000000;
  int myadd [numExamples];
  for(int i = 0 ; i < numExamples ; i++){myadd[i] = numExamples - i;}

  clock_t time;
  time = clock();
  mergeSort(myadd, 0, numExamples - 1);
  time = clock() - time;
  cout << "The time taken to sort 1,000,000 numbers is: " << float(time)/CLOCKS_PER_SEC << " secs" << endl;
}
