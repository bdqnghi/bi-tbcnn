#include <cstdlib>
#include <algorithm>
#include <random>

using namespace std;

template<class Iterator>
void quicksort(Iterator first, Iterator last) {
    int n = last - first;
    if (n < 2) return;
    
    default_random_engine generator;
    uniform_int_distribution<int> distribution(0, n - 1);
    iter_swap(first, first + distribution(generator));
    
    Iterator p = first, q = first;
    for (Iterator it = first + 1; it != last; ++it)
        if (*it < *first) {
            iter_swap(it, ++q);
            iter_swap(q, ++p);
        } else if (*it == *first) {
            iter_swap(++q, it);
        }
    iter_swap(first, p);
    quicksort(first, p);
    quicksort(q + 1, last);
}
