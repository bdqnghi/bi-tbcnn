#include "quicksort.h"

#include <ctime>
#include <cstdlib>

void QuickSort::sort(std::vector<int>& elements)
{
	quicksort(elements, 0, elements.size() - 1);
}

int QuickSort::partition(std::vector<int>& elements, int p, int r)
{
	int v = elements[r];
	int i = p - 1;

	for (int j = p; j < r; ++j) {
		if (elements[j] <= v) {
			++i;
			int tmp = elements[i];
			elements[i] = elements[j];
			elements[j] = tmp;
		}
	}

	int tmp = elements[i + 1];
	elements[i + 1] = elements[r];
	elements[r] = tmp;

	return (i + 1);
}

void QuickSort::quicksort(std::vector<int>& elements, int p, int r)
{
	if (p < r) {
		int q = partition(elements, p, r);
		quicksort(elements, p, q - 1);
		quicksort(elements, q + 1, r);
	}
}

int HoareQuickSort::partition(std::vector<int>& elements, int p, int r)
{
	int v = elements[p];
	int i = p - 1;
	int j = r + 1;
	
	while (1) {
		do { --j; } while (elements[j] > v);
		do { ++i; } while (elements[i] < v);


		if (i < j) {
			int tmp = elements[i];
			elements[i] = elements[j];
			elements[j] = tmp;
		} else {
			return j;
		}
	}
}

void HoareQuickSort::quicksort(std::vector<int>& elements, int p, int r)
{
	if (p < r) {
		int q = partition(elements, p, r);
		quicksort(elements, p, q);
		quicksort(elements, q + 1, r);
	}
}

int RandomQuickSort::random(int p, int r)
{
	std::srand(time(NULL));
    return ((rand() % (r - p + 1)) + p);
}

int RandomQuickSort::partition(std::vector<int>& elements, int p, int r)
{
	int i = random(p,r);
	int tmp = elements[i];
	elements[i] = elements[r];
	elements[r] = tmp;

	return QuickSort::partition(elements, p, r);
}

