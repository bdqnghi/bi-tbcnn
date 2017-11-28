#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;

void mergeSort(int* array, int size)
{
	int midPoint = 0;
	int i = 0;
	int j = 0;
	int k = 0;
	int p = 0;
	//int finalArray[size];
	//int temp = 0;
	//int temp2 = 0;
	//check base case (size == 1)
		//if true return nothing
	if (size == 1)
	{
		return;
	}
	//calculate midpoint
	midPoint = size / 2;
	//allocate sub arrays
	int *leftArray;
	int *rightArray;
	leftArray = new int[midPoint];
	rightArray = new int[midPoint];
	//copy data into sub arrays
	//cout << "HERE IN THE FUNCTION";
	for(i = 0; i < midPoint; i++)
	{
		memcpy(&leftArray, &array, sizeof(leftArray));
	}
	cout << "DEAD HERE?";
	i = 0;
	for(j = midPoint; j <= size; j++)
	{
		memcpy(&rightArray, &array[midPoint], sizeof(rightArray));
	}
	j = midPoint;
	//mergesort on left sub array (compare takes place on the merge)
	for(p = 0; p < size; p++)
	{
		if (leftArray[i] < rightArray[j])
		{
			array[k] = leftArray[i];
			i++;
			//k++;
		}
		else
		{
			array[k] = rightArray[j];
			j++;
			//k++;		
		}
	}
	//cout << "Or here DEAD?";
	/*if((leftArray[i] > leftArray[i+1]) && leftArray[i+1] < midPoint)
	{
		temp = leftArray[i+1];
		leftArray[i+1] = leftArray[i];
		leftArray[i] = temp;
		i++;
	}
	//mergesort on right sub array
	if((leftArray[j] > leftArray[j+1]) && leftArray[j] != size)
	{
		temp2 = leftArray[j+1];
		leftArray[j+1] = leftArray[j];
		leftArray[j] = temp2;
		j++;
	}
	//merge left and right into array
	//int *finalArray = new int[size];
	//memcpy(&finalArray, &leftArray + &rightArray, sizeof(size));
	*/
	//free left and right
	delete [] leftArray;
	delete [] rightArray;

}

int main(int argc, char * argv[])
{
	int array[5];
	int	i = 0;
	
    cout << "enter  the elements\n";
    for (i = 0; i < 5; i++)
    {
        cin >> array[i];
    }
	
    mergeSort(array, 5);
    cout << "sorted array\n";
    for (i = 0; i < 5; i++)
    {
        cout << array[i] << endl;
    }
    
}