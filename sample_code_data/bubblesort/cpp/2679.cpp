# include <iostream>

using namespace std;

int main(){
    int arr[]={8,9,6,5,4}, temp,swapped=1;
    int size = sizeof(arr)/sizeof(arr[0]);
    for(int pass=size-1;pass>=0 && swapped ;pass--){
        swapped = 0;
        for(int i=0;i<=pass-1;i++){
            if(arr[i]>arr[i+1]){
                temp=arr[i];
                arr[i]=arr[i+1];
                arr[i+1]=temp;
                swapped=1;
            }
        }
    }
    
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
}