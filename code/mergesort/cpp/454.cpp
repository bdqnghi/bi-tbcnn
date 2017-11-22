#include<iostream>

using namespace std;

void MergeSort(int A[],int low,int middle,int high)
{
    int B[high-low+1];
    int l=low,m=middle+1,i=0;
    for(;l<=middle && m<=high;)
    {
        if(A[l]<A[m])
            B[i++]=A[l++];
        else if(A[l]>A[m])
            B[i++]=A[m++];
        else
        {
            B[i++]=A[l++];
            m++;
        }
    }

    for(;l<=middle;l++)
        B[i++]=A[l];

    for(;m<=high;m++)
        B[i++]=A[m];

    for(l=low;l<=high;l++)
        A[l]=B[l-low];
}

void Merge(int A[],int low,int high)
{
    int middle=(low+high)/2;
    if(high>low)
    {
        Merge(A,low,middle);
        Merge(A,middle+1,high);
        MergeSort(A,low,middle,high);
    }
}

int main()
{
    int k,i;
    int A[100];

    cin>>k;
    i=0;
    while(k!=-1)
    {
        A[i++]=k;
        cin>>k;
    }

    Merge(A,0,i-1);

    for(k=0;k<i;k++)
        cout<<A[k]<<" ";
    cout<<endl;
    return 0;
}
