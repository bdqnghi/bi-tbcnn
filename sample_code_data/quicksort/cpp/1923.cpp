#include<stdlib.h>
#include<iostream>

using namespace std;

int arr[]={7,6,5,4,3,2,1,0,8,9,};

void interchange(int x,int y){
	int temp=arr[x];
	arr[x]=arr[y];
	arr[y]=temp;
	return;
}

int partition(int p,int q){
	int item=arr[p];
	int i=p;
	for(int j = p+1;j<=q;j++){
		if(arr[j] <= item){
			i++;
			interchange(i,j);
		}
	}
	interchange(p,i);
	return i;
}


int  quicksort(int p,int q){
	if(p == q)
	return arr[p];
	if(p < q){
		int m=partition(p,q);
		quicksort(p,m-1);
		quicksort(m+1,q);
	}
}


int main(){
	int len=sizeof(arr)/sizeof(int);
	quicksort(0,len-1);
	for(int i=0;i<len;i++)
	cout<<arr[i]<<" ";
	return 0;
}
