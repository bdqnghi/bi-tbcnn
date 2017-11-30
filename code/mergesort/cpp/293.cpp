#include <cstdlib>
#include "mergesort.h"

void Merge(ElemType *arr,int l,int m,int r)
{
	int i = l;
	int j = m + 1;
	int k = 0;

	ElemType *t = (ElemType*)malloc((r - l + 1) * sizeof(ElemType));

	if(!t)
		return;

	while(i <= m && j <= r)
	{
		t[k++] = (arr[i] < arr[j]) ? arr[i++] : arr[j++];
	}

	while(i <= m)
		t[k++] = arr[i++];

	while(j <= r)
		t[k++] = arr[j++];

	for(i = 0,j = l;j <= r;i++,j++)
		arr[j] = t[i];

	free(t);
}

void MergeSort(ElemType *arr,int begin,int end)
{
	int mid = 0;
	if(begin < end)
	{
		mid = (begin + end) / 2;
		MergeSort(arr,begin,mid);
		MergeSort(arr,mid + 1,end);
		Merge(arr,begin,mid,end);
	}
}

