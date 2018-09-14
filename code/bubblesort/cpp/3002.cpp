#include "array.h"
#include <iostream>

using namespace std;

static void BubbleSort(int a[], int len)
{
    bool changed = false;
    for (int i = len; i > 0; i--) {
        changed = false;
        for (int j = 0; j < i; j++) {
            if (a[j] > a[j + 1]) {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
                changed = true;
            }
        }
        if (!changed)
            break;
    }
    return;
}

int main()
{
    InitArray(arr, COUNT_MAX);
    cout << "Array:" << endl;
    PrintArray(arr, COUNT_MAX);

    BubbleSort(arr, COUNT_MAX);

    cout << "Array Afer BubbleSort:" << endl;
    PrintArray(arr, COUNT_MAX);
    
    return 0;
}
