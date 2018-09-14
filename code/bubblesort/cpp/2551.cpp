#include<iostream>
#include<stdlib.h>
using namespace std;
void bubblesort(int* A, int len);
void display(int* A, int len);
void bubblesort(int* A, int len) {
	bool swapped = true;
	int temp;
	int count = 0;
	while (swapped == true) {
		swapped = false;
		for (int i = 0; i < len - 1; i++) {
			if (A[i] > A[i + 1]) {
				temp = A[i];
				A[i] = A[i + 1];
				A[i + 1] = temp;
				swapped = true;
			}
		}
		count++;
		cout << "current pass: " << count << endl;
		display(A, len);
	}
}
void display(int* A, int len) {
	for (int i = 0; i < len; i++) {
		cout << A[i] << ' ';
	}
	cout << endl;
}
int main() {
	int a[15];
	int val;
	for (int i = 0; i < 15; i++) {
		val = (rand() + 1) % 100;
		a[i] = val;
	}
	cout << "Display before starting sort" << endl;
	display(a, 15);
	cout << "Display after starting sort" << endl;
	bubblesort(a, 15);
}