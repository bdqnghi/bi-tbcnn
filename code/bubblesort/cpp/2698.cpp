#include <bits/stdc++.h>

using namespace std;

void bubblesort(int a[], int N) {
	for(int i = 0; i < N - 1; i++) {
		for(int j = 0; j < N - 1 - i; j++) {
			if(a[j] > a[j + 1]) {
				int temp = a[j + 1];
				a[j + 1] = a[j];
				a[j] = temp;
			}
		}
	}
}

int main(void) {
	int N;
	cin >> N;
	int seq[N];
	for(int i = 0; i < N; i++) {
		cin >> seq[i];
	}
	bubblesort(seq, N);
	for(int i = 0; i < N; i++) {
		printf("%d ", seq[i]);
	} 
	return 0;
}
