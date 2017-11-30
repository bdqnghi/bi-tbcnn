/*

#include<stdio.h>


//to swap two values in an array.
void swap(int *a, int *b){ 
	int c = *a;
	*a = *b;
	*b = c;

}

void sort(int *arr, int length){

	partition(0, length)

}

void partition(int low, int length){ //leftPointer = 0, rightPointer = length - 1
	int high = length - 1;
	int pivot = (high -low)/2; //give a point to split the array at, rough estimate of what a middle value may be
	
	while (low < high){
		while (arr[low] < pivot){
			++lower;
		}
		while (arr[high] > pivot){
			--high;
		}
		swap(&arr[low], &arr[high]);
	}
	

}

int main(){
	int length = 8; //will give length of array "arr"
	int leftPointer = 0; //first element of array "arr"
	int rightPointer = length - 1;

	arr[length] = {1,2, 3, 8, 7, 6, 5, 4};

	Quicksort(arr, length);

} */
/* C implementation QuickSort */
#include<stdio.h>
 
// A utility function to swap two elements
void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
 
/* This function takes last element as pivot, places
   the pivot element at its correct position in sorted
    array, and places all smaller (smaller than pivot)
   to left of pivot and all greater elements to right
   of pivot */
int partition (int arr[], int low, int high)
{
    int pivot = arr[high];    // pivot
    int i = (low - 1);  // Index of smaller element
 
    for (int j = low; j <= high- 1; j++)
    {
        // If current element is smaller than or
        // equal to pivot
        if (arr[j] <= pivot)
        {
            i++;    // increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}
 
/* The main function that implements QuickSort
 arr[] --> Array to be sorted,
  low  --> Starting index,
  high  --> Ending index */
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now
           at right place */
        int pi = partition(arr, low, high);
 
        // Separately sort elements before
        // partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
 
/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
    
}
 
// Driver program to test above functions
int main()
{
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
    quickSort(arr, 0, n-1);
    printf("Sorted array: \n");
    printArray(arr,n);
    return 0;
}