// Bubble sort
// 9/1/2017
#include <iostream>
using namespace std;

void bubble_sort(int A[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = n - 1; j >= i + 1; j--) {
            if (A[j] < A[j - 1]) {
                int tmp = A[j];
                A[j] = A[j - 1];
                A[j-1] = tmp;
            }
        }
    }
}

int main()
{
    int A[] = {4,3,2,1};
    bubble_sort(A, 4);
    
    for (int i = 0; i < 4; i++)
        cout << A[i] << " ";
    cout << endl;
    return 0;
}
