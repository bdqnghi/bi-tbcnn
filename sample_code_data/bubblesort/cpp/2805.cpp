/*#include <iostream>
#include <Windows.h>
#include <time.h>
using namespace std;
int arr[7];
int i;
void selectionSort(int arr[], int n) {
      int i, j, minIndex, tmp;    
      for (i = 0; i < n - 1; i++) {
            minIndex = i;
            for (j = i + 1; j < n; j++)
                  if (arr[j] < arr[minIndex])
                        minIndex = j;
            if (minIndex != i) {
                  tmp = arr[i];
                  arr[i] = arr[minIndex];
                  arr[minIndex] = tmp;
            }
      }
}
int main()
{
	srand(time(0));
	int i = rand();
	for (int i = 0; i <= sizeof (arr)/sizeof (int); i++)
	{
		arr [i]=rand();
	}
	selectionSort(arr, 7);
	for (int i = 6; i>= 0; i--)
	{
		cout << arr[i] << endl;
		Sleep (rand()%2000);
	}
	system ("pause");
	return 0;
}*/