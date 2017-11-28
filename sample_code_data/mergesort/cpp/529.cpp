// Merge sort
// not considering the first element in the array

#include<iostream>
#include<cstdio>
#include<climits>
using namespace std;

void merge(int a[], int p, int q, int r){
	int n1 = q-p+1;
	int n2 = r-q;

	int L[n1+1], R[n2+1], i, j, k;

	for(i=1; i<=n1; i++)
		L[i] = a[p+i-1];

	for(i=1; i<=n2; i++)
		R[i] = a[q+i];

	L[n1+1] = INT_MAX;
	R[n2+1] = INT_MAX;
	i = j = 1;

	for(k=p; k<=r; k++){
		if(L[i] <= R[j])
			a[k] = L[i++];
		else
			a[k] = R[j++];
	}
}

void merge_sort(int a[], int p, int r){
	if(p < r){
		int q = (p+r)/2;
		merge_sort(a, p, q);
		merge_sort(a, q+1, r);
		merge(a, p, q, r);
	}
}

void display(int ar[], int size){
	for(int i=1; i<size; i++)
		cout<<ar[i]<<" ";
	cout<<endl;
}
int main(){
	int a[] = {-100,10,8,9,6,7,2,4,5,1,3};
	int size = 11;
	display(a,size);
	merge_sort(a, 1, 10);
	display(a,size);
}
