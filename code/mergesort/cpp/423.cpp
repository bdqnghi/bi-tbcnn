#include <iostream>
#include <time.h>
#include <stdlib.h> 
using namespace std;

void merge(int * arr,int begin,int mid,int last){
	int *aux;
	aux = new int[last+1];
	for(int i=begin;i<=last;i++)
		aux[i] = arr[i];

	int j= mid+1;
	int i= begin;
	for(int k = i;k <= last;k++){
		if(i > mid)
			arr[k] = aux[j++];
		else if(j > last)
			arr[k] = aux[i++];
		else if(aux[j] < aux[i])
			arr[k] = aux[j++];
		else
			arr[k] = aux[i++];
		
	}

}

void sort(int *arr,int begin,int last){
	if(last <= begin)
		return;
	int mid = begin + (last-begin)/2;
	sort(arr,begin,mid);
	sort(arr,mid+1,last);
	merge(arr,begin,mid,last);

}

int main(){
	int *b;
	int size = 100;
	b = new int[size];

	srand(time(NULL));
	for(int i=0;i<size;i++) b[i] = rand()%100+1;

    sort(b,0,size-1);

	for(int i=0;i<size;i++){
		cout << b[i]<<" ";
	}
	return 0;	
}