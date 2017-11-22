#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define PERM(x,y) {int t = (x); (x) = (y); (y) = t;}
/*
  Ordenar o array dado eficientemente
*/

int n, a[1000000];

int ler_dados() {
	if(scanf("%d",&n) != 1) return 0;
	int i;
	for(i=0;i<n;i++) scanf("%d",a+i);
}

// Como ajeitar para ficar eficiente mesmo quando
// o array for cheio de elementos repetidos?
// void quicksort(int l, int r)
// {
// 	if(l+1 >= r) return;
// 	int p = l + rand()%(r-l);
// 	PERM(a[p],a[r-1]);
// 	int i, k;
// 	for(i=k=l;i<r-1;i++) {
// 		if(a[i] < a[r-1]) {
// 			PERM(a[i],a[k]);
// 			k++;
// 		}
// 	}
// 	PERM(a[r-1], a[k]);
// 	quicksort(l,k);
// 	quicksort(k+1,r);
// }

int particiona(int left, int right)
{
	int i = left, j = right, p = a[left];
	while(i <= j)
	{
		while(a[i] <= p) ++i;
		while(a[j] > p) --j;
		if(i < j) PERM(a[i], a[j]);
	} 
	PERM(a[left], a[j]);
	return j;
}

void quicksort(int left, int right)
{
	if(left < right)
	{
		int split = particiona(left, right);
		quicksort(left, split-1);
		quicksort(split+1, right);
	}
}

void processa() {
	quicksort(0,n);
	int i;
	for(i=0; i<n; i++) printf("%d ",a[i]);
	printf("\n");
}

int main() {
	// freopen ("in.txt","r",stdin);
	freopen ("out.txt","w",stdout);
	srand(time(NULL));
	//while(ler_dados()) processa();
	
	/*Apenas testando com numeros repetidos*/
	int i;
	n = 100;
	for(i = 0; i < n; i++) a[i] = rand()%1000;
	//for(i = 0; i < n; i++) a[i] = 1;
	processa();
	
	return 0;
}
