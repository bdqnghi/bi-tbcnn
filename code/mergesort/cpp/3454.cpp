#include<iostream>
using namespace std;
void merge(int *arr,int start,int ends){
    int i,j,b[200],k=start;   //  k starts from start not from 0 as initial values will be filled
    int mid=(start+ends)/2;
    i=start;
    j=mid+1;
    while(i<=mid &&j<=ends){
            if(arr[i]>arr[j]){
                b[k++]=arr[j++];
            }
            if(arr[j]>arr[i]){
                b[k++]=arr[i++];
            }
            if(arr[i]==arr[j]){
                b[k++]=arr[i++];
            }
    }
    if(i<=mid){
        while(i<=mid){
            b[k++]=arr[i++];
        }
    }
    if(j<=ends){
        while(j<=ends){
            b[k++]=arr[j++];
        }
    }
for(i=start;i<=ends;i++){
        arr[i]=b[i];
    }
}
void mergesort(int *arr,int start,int ends){
    //if(start==end) return;
    int mid = (start + ends)/2;
    if(start<ends){
    mergesort(arr,start,mid);
    mergesort(arr,mid+1,ends);
    merge(arr,start,ends);
    }
}
int main(){
    int arr[100],start=0,ends,n;
    cout<<"enter size";
    cin>>n;
    ends=n-1;
    cout<<"enter elements";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    mergesort(arr,start,n-1);
        for(int i=start;i<=ends;i++){
            cout<<" "<<arr[i];
    }
}
