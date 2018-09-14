#include "stdafx.h"

int bubbleSort(int a[],int length)
{	
	int i, j, temp;

	for (i = 0; i<length; i++)
	{
		int flag = 0;        //taking a flag variable
		for (j = 0; j<length - i - 1; j++)
		{
			if (a[j] > a[j + 1])
			{
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
				flag = 1;         //setting flag as 1, if swapping occurs
			}
		}
		if (!flag)             //breaking out of for loop if no swapping takes place
		{
			break;
		}
	}

	return 0;
}