#include<iostream>
using namespace std;
/*
	TODO
	Dual Pivot quicksort
	Randomized Pivot selection
	Median of three pivot selection
	Iterative Quick Sort
	Quickselect algorithm -> nth element
*/
void printArray(int *input, int size);
void qsort(int *input,int low, int high);
int partition(int *input, int low, int high);
void swap(int *a, int *b);
int main() {
	int input[] = {13,19,9,5,12,8,7,4,21,2,6,11};//{9,8,7,6,5,4,3,2,1,0,-1};
	int size = sizeof(input) / sizeof(input[0]);

	printArray(input,size);
	qsort(input,0,size-1);
	printArray(input,size);

	getchar();
	return 0;
}
int partition(int *input, int low, int high) {
	int i = low;
	int x = input[high];

	for (auto j = low; j < high; j++) {
		if (input[j]<x) {
			swap(&input[i], &input[j]);
			i++;
		}
	}
	swap(&input[i], &input[high]);
	return i;
}
void qsort(int *input, int low, int high) {
	if (low>=high) {
		return;
	}
	int pivot = partition(input, low, high);
	qsort(input, low, pivot-1);
	qsort(input, pivot+1, high);
}
void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}
void printArray(int *input, int size) {
	for (auto i = 0; i < size; i++) {
		cout << input[i] << " ";
	}
	cout << endl;
}