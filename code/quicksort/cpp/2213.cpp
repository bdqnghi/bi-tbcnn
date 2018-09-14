#include<iostream>
#include<algorithm>
using namespace std;

int PARTITION(int A[], int p, int r) {
    int i = p - 1;
    int x = A[r];
    for (int j = p; j < r; j++)
        if (A[j] <= x) {
            i++;
            swap(A[i], A[j]);
        }
    swap(A[i + 1], A[r]);
    return i + 1;
}

void QUICKSORT(int A[], int p, int r) {
    if (p < r) {
        int q = PARTITION(A, p, r);
        QUICKSORT(A, p, q - 1);
        QUICKSORT(A, q + 1, r);
    }
    return;
}

int main() {
    int A[] = { 9,10,11,7,1,2,3,6,5,8,4 };
    QUICKSORT(A, 0, 10);
    for (int i = 0; i < 11; i++)
        cout << A[i] << " ";
    return 0;
}