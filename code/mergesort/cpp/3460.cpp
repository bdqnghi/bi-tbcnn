#include <vector>

using namespace std;

template<class Iterator>
int mergesort(Iterator first, Iterator last) {
    int n = last - first;
    if (n < 2) return 0;
    Iterator mid = first + n / 2;
    int sum = mergesort(first, mid) + mergesort(mid, last);

    typedef typename iterator_traits<Iterator>::value_type value_type;
    vector<value_type> seq(n);
    auto r = seq.begin();
    Iterator p = first, q = mid;

    while (p < mid && q < last)
        if (*p <= *q) {
            *r++ = *p++;
        } else {
            *r++ = *q++;
            sum += mid - p;
        }
    while (p < mid) *r++ = *p++;
    while (q < last) *r++ = *q++;
    for (int i = 0; i < n; ++i)
        *(first + i) = seq[i];
    return sum;
}
