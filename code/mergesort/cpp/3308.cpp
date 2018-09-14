#include<iostream>
#include<cstdio>
 
using namespace std;
 
int a[100],count=0;
 
void mergesort(int low , int high);
void merge(int low,int mid,int high);
 
int main()
{
    int n ;
    cin>>n;
    for(int i=1;i<=n;i++)
     cin>>a[i];
     mergesort(1,n);
     for(int i=1;i<=n;i++)
     cout<<a[i]<<endl;
    return 0;
}
 
 
void mergesort(int low , int high)
{
    int mid;
    if(low<high)
    {
        mid=(low+high)/2;
        mergesort(low,mid);
        mergesort(mid+1,high);
        merge(low,mid,high);
    }
}
 
void merge(int low,int mid,int high)
{
 
    int b[100],h,i,j;
    h=low;
    i=low;
    j=mid+1;
    while(h<=mid and j<=high)
    {
        if(a[h]<=a[j])
        {
            b[i]=a[h];
            h++;
        }
        else
        {
            b[i]=a[j];
            j++;
        }
        i++;
     }
     if(h>mid)
       for(int k=j;k<=high;k++,i++)
        b[i]=a[k];
    else
       for(int k=h;k<=mid;k++,i++)
        b[i]=a[k];
    for(int k=low;k<=high;k++)
        a[k]=b[k];
 
}