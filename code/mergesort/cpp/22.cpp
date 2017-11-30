#include <bits/stdc++.h>

using namespace std;

void merge(int A[],int s,int e){
    int p = s,k = 0;
    int arr[e - s + 1];
    int m = (s+e)/2;
    int j = m+1;
    for(int i=s;i<=e;i++){
        if(j > e){
            arr[k++] = A[p++];
        }
        else if(p > m){
            arr[k++] = A[j++];
        }
        else if(A[p] < A[j]){
            arr[k++] = A[p++];
        }else{
            arr[k++] = A[j++];
        }
    }
    for(int i=0;i<k;i++){
        A[s++] = arr[i];
    }
}

void mergesort(int arr[],int s,int e){
    if(s < e){
        int mid = (s+e)/2;
        mergesort(arr,s,mid);
        mergesort(arr,mid+1,e);
        merge(arr,s,e);
    }
}

int main(){
    int arr[] = {64,25,12,22,11};
    int n = sizeof(arr)/sizeof(int);
    mergesort(arr,0,n-1);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
return 0;
}
