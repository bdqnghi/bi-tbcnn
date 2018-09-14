#include <stdio.h>
#include <stdlib.h>

static void swap(int *lhs, int *rhs)
{
	int tmp = *lhs;
	*lhs = *rhs;
	*rhs = tmp;
}

static int partition(int ar[], const int len)
{
	int i, pvt=0;

	// swap random slot selection to end.
	//  ar[len-1] will hold the pivot value.
	swap(ar+rand()%len,ar+len-1);
	for (i=0; i<len; i++) {
		if (ar[i] < ar[len-1])
			swap(ar+i,ar+pvt++);
	}

	// swap the pivot value into position
	swap(ar+pvt,ar+len-1);
	return pvt;
}

// recursive in-place quicksort
static void _quicksort(int ar[], const int len)
{
	if (len < 2) return; 
	int pvt = partition(ar,len);
	_quicksort(ar,pvt++); // note increment. skips pivot slot
	_quicksort(ar+pvt,len-pvt);
}

// non-recursive in-place quicksort
void quicksort_nr(const int elements, int *restrict arr) {
	const int depth=300;
	int  piv, beg[depth], end[depth], i=0, L, R, swap ;
	beg[0]=0;
	end[0]=elements;
	while (i>=0) {
		L=beg[i]; 
		R=end[i]-1;
		if (L<R) {
			piv=arr[L];
			while (L<R) {
				while (arr[R]>=piv && L<R) R--; 
				if (L<R) arr[L++]=arr[R];
				while (arr[L]<=piv && L<R) L++; 
				if (L<R) arr[R--]=arr[L]; 
			}
			arr[L]=piv; 
			beg[i+1]=L+1; 
			end[i+1]=end[i]; 
			end[i++]=L;
			if (end[i]-beg[i]>end[i-1]-beg[i-1]) {
				swap=beg[i]; 
				beg[i]=beg[i-1]; 
				beg[i-1]=swap;
				swap=end[i]; 
				end[i]=end[i-1]; 
				end[i-1]=swap; 
			}
		}
		else 
			i--;
	}
}

void quicksort(const int n, int *restrict a)
{
	_quicksort(a,n);
}


//#include <time.h>
//int main()
//{
	//srand((unsigned int)time(NULL));

	//const int N = 20;
	//int data[N];

	//for (int i=0; i<N; ++i)
	//{
		//data[i] = rand() % 50 + 1;
		//printf("%d ", data[i]);
	//}

	//quicksort(data, N);

	//for (int i=0; i<N; ++i)
		//printf("%d ", data[i]);


	//return 0;
//}
