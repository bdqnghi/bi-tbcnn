// Merge sort.

#include<iostream>

using namespace std;

void mergesort(int*, int);
void merge(int*, int*, int*, int, int);
void display(int* , int);

void mergesort(int *arr, int size){
	
	int n = size;
	
	if(n < 2)
		return;
		
	int mid = n/2;
	
	// Splitting original array into two arrays.
	// Repeating same recursively till we have all numbers in one element arrays.
	// Thus we'll be having all numbers in 12(in this case) different single element arrays.
	int left[mid], right[n-mid];
		
	// initialising left array
	for (int i = 0; i < mid; i++)
		left[i] = arr[i];
	
	// initialising right array		
	for (int j = mid; j < n; j++)
		right[j-mid] = arr[j];
			
	// calling below function recursively till we all left half elements of original array in single element arrays
	mergesort(left, mid);
	
	// calling below function recursively till we all right half elements of original array in single element arrays
	mergesort(right, n-mid);
	
	// merging splitted arrays
	merge(left, right, arr, mid, n-mid);
	
}

void merge(int* l, int* r, int* a, int sizeleft, int sizeright){
	
	int nl, nr; 
	int i, j, k;
	
	nl = sizeleft;
	nr = sizeright;
	
	i = 0; // smallest unpicked in left
	j = 0; // smallest unpicked in right
	k = 0; // position to be filled in arr
	
	// comparing elements of splitted arrays and inserting elements into original array in ascending order
	while ((i < nl) && (j < nr)){
		
		if (l[i] <= r[j]){
			
			a[k] = l[i];
			i++;
			
		}
		else {
			
			a[k] = r[j];
			j++;
			
		}
		
		k++;
	}
	
	// executed if left temporary array still has elements to be compared
	while (i < nl){
		
		a[k] = l[i];
		i++;
		k++;
		
	}
	
	// executed if right temporary array still has elements to be compared
	while (j < nr){
		
		a[k] = r[j];
		j++;
		k++;
		
	}

}

void display(int *arr, int size){
	
	for (int i = 0; i < size; i++)
		cout << arr[i] << "\t";

}

int main()
{
	
	int b[] = {12,10,43,23,78,45,123,56,98,41,90,24};
	
	int size = sizeof(b)/sizeof(int);
	
	cout << "\nOriginal array :\n";
	display(b, size);
	mergesort(b,size);
	cout << "\nArray after merge sort :\n";
	display(b, size);

}
