#include <iostream>
#include <queue>
#include <bits/stdc++.h>
using namespace std;

int merge(int a[],int mid,int l,int r)
{   int n1,n2;
    n1 = mid-l+1;
    n2 = r-mid;
    int arL[n1];
    int arR[n2];
    for(int u=0;u<n1;u++)
    {
        arL[u]=a[l+u];
    }
    for(int v=0;v<n2;v++)
    {
        arR[v] = a[mid+1+v];      
    }

    int li=0, ri=0;
    int k=l;
    while(li<n1 && ri<n2)
    {
       if (arL[li]<=arR[ri])
       {
           a[k] = arL[li];
           k++;
           li++;
       }
       else
       {
           a[k] = arR[ri];
           ri++;
           k++;
       }
    }
    while(li<n1)
    {
        a[k] = arL[li];
        k++;
        li++;
    }
    while(ri<n2)
    {
        a[k] = arR[ri];
        ri++;
        k++;
    }
}

int mergesort(int a[],int left,int right)
{
    
    if(left<right)
    {
        int mid = (int)((right+left)/2);
        mergesort(a,left,mid);
        mergesort(a,mid+1,right);
        merge(a,mid,left,right);
    }
}

int main()
{
    int a[8] = {9,4,5,6,2,8,7,1};   
    mergesort(a,0,7);
    for(int i=0;i<8;i++)
    {
        cout<<a[i]<<" ";
    }
    
}
