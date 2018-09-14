#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <limits.h>

using namespace std;

void print(int *a, int n){

	int i;
	for(i=0; i<n; i++){
		cout<<a[i]<<" ";
	}
	cout<<"\n";
}

void merge(int *a, int p, int q, int r){

	int n1, n2, i, j, k, q1, q2;
	n1 = q-p+1;
	n2 = r-q;
	
	int *left = new int[n1+1];
	int *right = new int[n2+1];

	for(i=0; i<n1; i++){
		left[i] = a[p+i];
	}
	
	for(i=0; i<n2; i++){
		right[i] = a[q+i+1];
	}

	left[n1] = INT_MAX;
	right[n2] = INT_MAX;

	i=0; 
	j=0;

	for(k=p; k <= r; k++){
		if(left[i] <= right[j]){
			a[k] = left[i];
			i++;
		}
		else{
			a[k] = right[j];
			j++;
		}
	}
}		

void mergesort(int *a, int p, int r){

	int q;
	if(p < r){
		q = (p+r)/2;
		mergesort(a, p, q);
		mergesort(a, q+1, r);
		merge(a, p, q, r);
	}

}

int main(){
	
	int n, i;
	cin >> n;
	int *a = new int[n];

	for(i=0; i<n; i++){
		a[i] = rand()%n;
	}
	//print(a, n);

	mergesort(a, 0, n-1);
	print(a, n);
}
	
