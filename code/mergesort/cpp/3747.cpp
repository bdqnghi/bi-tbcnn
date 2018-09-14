#include <iostream>
#include <cmath>
using namespace std;

const int INPUT_SIZE = 10;

// A simple print function
void print(int *input)
{
    for ( int i = 0; i < INPUT_SIZE; i++ )
        cout << input[i] << " ";
    cout << endl;
}

void merge(int* a, int p, int r)
{
	int mid = floor((p+r)/2);
	int tmp_idx = 0;
	int l_idx = p;
	int r_idx = mid + 1;

	// tmp array for storing merged result
	int tmp[r-p+1];
	
	// do the actual merge
	
	// 1. merge until it's clear that right/upper half to be merged
	//    is greater than the left/lower half
	while (l_idx <= mid && r_idx <= r) {
		if (a[l_idx] < a[r_idx]) {
			tmp[tmp_idx++] = a[l_idx++];
		} else {
			tmp[tmp_idx++] = a[r_idx++];
		}
	}
	
	// 2. copy remaining in left array
	while (l_idx <= mid) {
		tmp[tmp_idx++] = a[l_idx++];
	}
	
	// 3. copy remaining in right array
	while (r_idx <= r) {
		tmp[tmp_idx++] = a[r_idx++];
	}
		
	// copy from temp array, overriding passed in array
	for (int i = p; i <= r; i++) {
		a[i] = tmp[i-p];
	}
} 
void merge_sort(int* input, int p, int r)
{
	if (p < r) {
		int mid = floor((p+r)/2);
		merge_sort(input, p, mid);
		merge_sort(input, mid+1, r);
		merge(input, p, r);
	}
}

int main()
{
    int input[INPUT_SIZE] = {500, 700, 800, 100, 300, 200, 900, 400, 1000, 600};
    cout << "Input:  ";
    print(input);
    merge_sort(input, 0, 9);
    cout << "Output: ";
    print(input);
    return 0;
}