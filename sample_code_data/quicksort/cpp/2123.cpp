#include <stdio.h>
#include <chrono>
#include <cstdlib>

#define SIZE (100000)

void quick_sort (int *a, int n) {
    int i, j, p, t;
    if (n < 2)
        return;
    p = a[n / 2];
    for (i = 0, j = n - 1;; i++, j--) {
        while (a[i] < p)
            i++;
        while (p < a[j])
            j--;
        if (i >= j)
            break;
        t = a[i];
        a[i] = a[j];
        a[j] = t;
    }
    quick_sort(a, i);
    quick_sort(a + i, n - i);
}

int main () {
    srand(time(NULL));
    int a[SIZE];
    int n = sizeof a / sizeof a[0];
    int i = 0;
    do
    {
        a[i] += rand();
        i++;
    }while (i < SIZE);

    using namespace std::chrono;

    steady_clock::time_point t1 = steady_clock::now();

    quick_sort(a, n);

    steady_clock::time_point t2 = steady_clock::now();

    duration<double> time_span = duration_cast<duration<double>>(t2 - t1);

    double number = time_span.count();

    printf("%f", number);

    return 0;
}