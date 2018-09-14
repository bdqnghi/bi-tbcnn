#include <bits/stdc++.h>
using namespace std;
void merge(int arr[], int start1, int end1, int start2, int end2) {
	//creating a temporary array to merge the 2 sorted arrays (1st array from start1 to end1 and 2nd array from start2 to end2)
	int *temp = new int[end2 - start1 + 1];
	int tempindex = 0, index1 = start1, index2 = start2;
	//merging 2 sorted arrays into a temporary array
	while(index1 <= end1 && index2 <= end2) {
		if(arr[index1] <= arr[index2]) temp[tempindex++] = arr[index1++];
		else temp[tempindex++] = arr[index2++];
	}
	while(index1 <= end1) temp[tempindex++] = arr[index1++];
	while(index2 <= end2) temp[tempindex++] = arr[index2++];
	//copying the temporary (sorted) array into the original array 
	for(int i = start1; i <= end2; i++) {
		arr[i] = temp[i-start1];
	}
	//deleting the temporary array
	delete[] temp;
}
void mergesort(int arr[], int low, int high) {
	if(low == high) return;
	int mid = (low + high) / 2;
	//first half sorted array
	mergesort(arr, low, mid);
	//second half sorted array
	mergesort(arr, mid + 1, high);
	//merging the 2 sorted arrays
	merge(arr, low, mid, mid + 1, high);	
}

int main () {
	int n; cin>>n;
	int arr[n];
	for(int i = 0; i < n; i++) cin>>arr[i];
	mergesort(arr, 0, n-1);
	for(int i = 0; i < n; i++) cout<<arr[i]<<" ";
	return 0;
}
