#include<iostream>
using namespace std;


void Qsort(int a[],int f,int l)
{
   if(f<l)
   {
        int i=f;
        int j=l;
        int pivot = a[f],temp;
    while(i<j)
    {
        while(a[i]<=pivot && i<l)
            i++;
        while(a[j]>pivot)
            j--;
        if(i<j)
        {
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }
    }
    temp=a[j];
     a[j]=pivot;
     a[f]=temp;
    Qsort(a,f,j-1);
    Qsort(a,j+1,l);

   }
}
int main(void)
{
    int n;
    cout<<"Enter Total number:\n";
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++) cin>>a[i];
    Qsort(a,0,n-1);
    for(int i=0;i<n;i++) cout<<a[i]<<" ";
    return 0;
}
