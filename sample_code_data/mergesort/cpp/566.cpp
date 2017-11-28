#include<bits/stdc++.h>
using namespace std;
int arr[100],tmp[100];
void mergearrays(int low1,int up1,int low2,int up2)
{    int i=low1;int j=low2;int k=low1;
    while(i<=up1&&j<=up2)
    {
        if(arr[i]<arr[j])
        {
            tmp[k++]=arr[i++];
        }
        else if(arr[i]>arr[j])
        {
            tmp[k++]=arr[j++];
        }
        else
        {
            tmp[k++]=arr[i++];
          //  j++;
        }
    }
    while(i<=up1)
        tmp[k++]=arr[i++];
    while(j<=up2)
        tmp[k++]=arr[j++];

}
void copyarrays(int low,int up)
{
    for(int i=low;i<=up;i++)
        arr[i]=tmp[i];
}

void mergesort(int low,int up)
{
    if(low<up)
    {    int mid=(low+up)/2;
        mergesort(low,mid);
        mergesort(mid+1,up);
        mergearrays(low,mid,mid+1,up);
        copyarrays(low,up);
    }

}
int main()
{
    memset(arr,0,sizeof(arr));
     memset(tmp,0,sizeof(tmp));
     cout<<"enter the array size followed by elements\n";
     int n;
     cin>>n;
     for(int i=0;i<n;i++)
     {
         cin>>arr[i];
     }
     mergesort(0,n-1);
     cout<<"----------\nsorted elements are:\n";
        for(int i=0;i<n;i++)
     {
        cout<<arr[i]<<"\t";
     }
     return 0;
}













