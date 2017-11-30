#include <iostream>

using namespace std;

template<class T>
void bubblesort(T nums[], int n) {
	for(int i=0;i<n-1;i++) {
		for(int j=0;j<n-i-1;j++) {
			if( nums[j] > nums[j+1]) {
				swap(nums[j], nums[j+1]);
			}
		}
	}				
}

template<class T>
void swap(T& x, T& y) {
	T temp = x;
	x = y;
	y = temp;
}

template< class T>
void showArray(T data[], int n) {
	for(int i=0;i<n;i++)
		cout << data[i] << " ";
}

main() 
{
    
	char nums[] = {'b','a','e','d'};
	int n = sizeof(nums)/sizeof(nums[0]);
	
	cout << n << endl;
	
	bubblesort(nums, n);
	showArray(nums, n);
}