#include <bits/stdc++.h>
using namespace std;
void quicksort(int arr[], int low, int high) {
	if(low >= high) return;
	//elements on or before wall are less than pivot (a value, not an index).
	int walltill = low - 1, pivot = arr[high];
	for(int i = low; i <= high - 1; i++) {
		//if current element <= pivot, move wall 1 step ahead and swap element at wall with current element.
		if(arr[i] <= pivot) {
			swap(arr[walltill + 1], arr[i]);
			walltill++;
		}
	}
	//finally put pivot in its correct position as in the final sorted array.
	swap(arr[high], arr[walltill + 1]);
	//now apply quicksort on 2 array segments on either side of the current pivot.
	quicksort(arr, low, walltill);
	quicksort(arr, walltill + 2, high);
}

int main () {
	int n; cin>>n;
	int arr[n];
	for(int i = 0; i < n; i++) cin>>arr[i];
	quicksort(arr, 0, n-1);
	for(int i = 0; i < n; i++) cout<<arr[i]<<" ";
	return 0;
}
