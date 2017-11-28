#include "quicksort.h"


void QuickSort::quickSort(int *array, int p, int r) {
    int q;
    if (p < r) {
	q = partition(array, p, r);
	quickSort(array, p, q - 1);
	quickSort(array, q + 1, r);
    }
}

int QuickSort::partition(int *array, int p, int r) {
    int x = array[r];
    int i = p - 1;
    int j;
    for (j = p; j < r; j++) {
	if (array[j] <= x) {
	    i += 1;
	    swap(&array[i], &array[j]);
	}
    }
    swap(&array[i + 1], &array[r]);
    return i + 1;
}

void QuickSort::swap(int *lhs, int *rhs) {
    int temp = *lhs;
    *lhs = *rhs;
    *rhs = temp;
}
