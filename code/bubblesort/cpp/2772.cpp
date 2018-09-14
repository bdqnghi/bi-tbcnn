#include "bubblesort.h"
#include <algorithm>

void BubbleSort::sort(int *array, int first, int last)
{
    for (int i = first; i <= last; i++)
        for (int j = first; i <= last - j - 1; j++)
            if (array[j] > array[j + 1])
                std::swap(array[j], array[j + 1]);
}
