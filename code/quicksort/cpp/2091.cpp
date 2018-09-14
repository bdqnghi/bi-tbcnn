#include "quicksort.h"

void QUICKSORT( int A[], int inferior, int superior ) 
{
	int pivot, i, j, t;
	static int counter = 0;
	i = inferior;
	j = superior;
	pivot = A[(i + j) / 2];

	do {
		while ( (i < superior) && (A[i] < pivot) ) i++;
		while ( (j > inferior) && (A[j] > pivot) ) j--;
		
		if ( i <= j )
		{
			t    = A[i];
			A[i] = A[j];
			A[j] = t;
			i++;
			j--;
		}
	} while ( i <= j );

	if ( inferior < j ) 
		QUICKSORT( A, inferior, j );
	if (i < superior)
		QUICKSORT( A, i, superior );
}
