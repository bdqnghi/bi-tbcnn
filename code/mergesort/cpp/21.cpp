//this program implements mergesort 
//time complexity is O(n log n)

#include<iostream>
using namespace std;
void merge(int arr[],int l,int m,int r){
	int i,j,k;
	int n1,n2;
	n1=m-l+1;
	n2=r-m;
	//declare temporary arrays and copy the data
	int L[n1],R[n2];
	for(i=0;i<n1;i++){
		L[i]=arr[l+i];
	}
	for(i=0;i<n2;i++){
		R[i]=arr[m+1+i];
	}
	i=j=0;
	k=l;
	while(i<n1 && j<n2){
		if(L[i] <= R[j]){
			arr[k]=L[i];
			i++;k++;
		}
		else{
			arr[k]=R[j];
			j++;k++;
		}
	}
	//if any one of the arrays exhausts
	while(i<n1){
		arr[k]=L[i];
		i++;k++;
	}
	while(j<n2){
		arr[k]=R[j];
		j++;k++;
	}
}
void mergesort(int arr[],int low,int high){
	if(low < high){
		int mid=(low+high)/2;
		mergesort(arr,low,mid);
		mergesort(arr,mid+1,high);
		merge(arr,low,mid,high);
	}
}
main(){
	int arr[]={10,1,78,29,0};
	int n=sizeof(arr)/sizeof(arr[0]);
	for(int i=0;i<n;i++){
                cout<<arr[i]<<" ";
        }
        cout<<endl;
	mergesort(arr,0,n-1);
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}
