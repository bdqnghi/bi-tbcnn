#include <bits/stdc++.h>

using namespace std;

int partition (int a[], int p, int r) {
	int x = a[r];
	int i = p - 1;
	int j;

	for (j = p; j < r; j++) {
		if (a[j] <= x) {
			i++;
			swap(a[j],a[i]);
		}
	}
	swap(a[i + 1], a[r]);
	return (i + 1);
}

void quicksort(int a[], int p, int r) {
	int q;
	if (p < r) {
		q = partition(a, p, r);
		quicksort(a, p, q - 1);
		quicksort(a, q + 1, r);	
	}
}

int main() {
	int i,a[] = {2,6,3,8,12,1,0};
	quicksort(a,0,6);
	for (i = 0; i < 7; i++)
		cout << a[i] << " ";

	return 0; 
}
