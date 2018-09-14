#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define SIZE 10
int arr[SIZE];

void bubbleSort(int n);

int main() {
    int i;

    for (i = 0; i < SIZE; i++) {    // input
        arr[i] = rand() % 20;
    }

    bubbleSort(SIZE);    // sort

    for (i = 0; i < SIZE; i++) {    // output
        cout << arr[i] << endl;
    }

    return 0;
}

void bubbleSort(int n) {
      bool swapped = true;
      int j = 0;
      int tmp;
      while (swapped) {
            swapped = false;
            j++;
            for (int i = 0; i < n - j; i++) {
                  if (arr[i] > arr[i + 1]) {
                        tmp = arr[i];
                        arr[i] = arr[i + 1];
                        arr[i + 1] = tmp;
                        swapped = true;
                  }
            }
      }
}
