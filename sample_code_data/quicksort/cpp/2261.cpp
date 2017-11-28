#include <iostream>
#include "allsorts.h"

using namespace std;

void quicksort(int mass[],int l, int r){
	int i = l;
	int	j = r; 
	int x = mass[(l + r) / 2];
	do {
		while (mass[i] < x) ++i;
		while (mass[j] > x) --j;

		if (i <= j) 
		  {
			if (mass[i] > mass[j]) 
			swap(mass [i], mass[j]);
			++i;
			--j;
		  }
	   } while (i <= j);

	if (i < r)
	{
		quicksort(mass, i, r);
	}
	if (l < j)
	{
		quicksort(mass, l, j);
	}
}
