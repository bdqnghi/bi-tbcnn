
#include "basic.h"
#include "quicksort.h"

// rudimentary partition routine
int partition(Aux A[], int p, int r) {
    double x = A[r].val;
    double dtmp = 0;
    int itmp = 0;
    int i = p - 1;
    int j = 0;

    for (j = p; j <= r-1; j++) {
        if (A[j].val > x) {
            // exchange A[i], A[j]
            i = i + 1;
            itmp = A[i].idx;
            dtmp = A[i].val;
            A[i].idx = A[j].idx;
            A[i].val = A[j].val;
            A[j].idx = itmp;
            A[j].val = dtmp;
        }
    }

    // exchange A[i+1], A[r]
    itmp = A[i+1].idx;
    dtmp = A[i+1].val;
    A[i+1].idx = A[r].idx;
    A[i+1].val = A[r].val;
    A[r].idx = itmp;
    A[r].val = dtmp;
    return i+1;
}

// randomized partition interface
// RANDOMIZED = 1, apply randomized partition,
// otherwise, it is a regular transition routine
int randomized_partition(Aux A[], int p, int r) {

#if RANDMIZED
    double dtmp = 0;
    int itmp = 0;

    // randomly pick an index from [p..r]
    int i = p + (rand() % (r - p + 1));

    if (i != r) {
        // exchange A[i], A[r]
        itmp = A[i].idx;
        dtmp = A[i].val;
        A[i].idx = A[r].idx;
        A[i].val = A[r].val;
        A[r].idx = itmp;
        A[r].val = dtmp;
    }
#endif

    return partition(A, p, r);
}

// main entry of quick sort routine
void randomized_quicksort(Aux A[], int p, int r) {
    if (p < r) {
        int q = randomized_partition(A, p, r);
        randomized_quicksort(A, p, q-1);
        randomized_quicksort(A, q+1, r);
    }
}
