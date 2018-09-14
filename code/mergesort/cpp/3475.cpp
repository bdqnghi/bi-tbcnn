#include <iostream>
using namespace std;

void Merge(int *arr, int *larr, int *rarr, int lsize, int rsize){
    
	int i = 0, j = 0, k = 0;
	while(i < lsize && j < rsize){
		if(larr[i] < rarr[j])
			arr[k++] = larr[i++];
		else
			arr[k++] = rarr[j++];			
	}

	while(i < lsize)
        arr[k++] = larr[i++];
    while(j < rsize)
        arr[k++] = rarr[j++];

}

void MergeSort(int *arr, int size){
	if(size < 2)
		return;

	int mid = (size+1)/2;
	int larr[mid], rarr[size-mid];
	
	for(int i=0; i<mid; ++i)
		larr[i] = arr[i];
	
	for(int i=0; i<mid; ++i)
		rarr[i] = arr[i+mid];

	MergeSort(larr, sizeof(larr)/sizeof(int));
	MergeSort(rarr, sizeof(rarr)/sizeof(int));

	Merge(arr, larr, rarr, sizeof(larr)/sizeof(int), sizeof(rarr)/sizeof(int));

}


int main(){
	int arr[] = {1, 5, 4, 254, 55, 5, 41, 4, 4, 5, 1, 55, 4, 11, 5, 7, 9, 4, 1, 23, 79};
	int size  = sizeof(arr)/sizeof(int);
	MergeSort(arr, size);


	for(int i = 0; i < size; ++i)
		cout<<arr[i]<<" ";

}