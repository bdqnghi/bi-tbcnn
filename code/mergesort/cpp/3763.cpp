#include "mergesort.h"
#include <cmath>

void MergeSort::sort(std::vector<int>& elements)
{ 
	merge_sort(elements, 0, elements.size() - 1);
}

void MergeSort::merge(std::vector<int>& elements, int p, int q, int r)
{
	
	std::vector<int> R;
	std::vector<int> L;

	L.insert(L.end(), elements.begin() + p, elements.begin() + q + 1);
	R.insert(R.end(), elements.begin() + q + 1, elements.begin() + r + 1);

	auto left = L.begin();
	auto right = R.begin();

	for (auto e = (elements.begin() + p); e != (elements.begin() + r); e++) {
		if (left == L.end()) *e = *(right++); // L empty use R
		else if (right == R.end()) *e = *(left++); // R empty use L
		else if (*left < *right) *e = *(left++); // Assign and move to next whatever is smaller 
		else *e = *(right++); 
	}
	
}

void MergeSort::merge_sort(std::vector<int>& elements, int p, int r)
{
	if (p < r) {
		int q = std::floor((p + r) / 2);
		merge_sort(elements, p, q);
		merge_sort(elements, q+1, r);
		merge(elements,p,q,r);
	}
}


