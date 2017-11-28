#include<iostream>
 using namespace std;

void Merge(int a[],int first,int mid,int last)
{
    int n=mid-first+1   ,  m=last-mid;

   int suba1[n],suba2[m];

   int j=0;
   for(int i=first;i<=mid;i++)       // subarray1 initialized  mid-first+1=n
        suba1[j++]=a[i];                     //started with first because of array a

    j=0;
    for(int i=mid+1;i<=last;i++)             // subarray2 initialized
        suba2[j++]=a[i];                     // started with mid+1 because of array a

     int k=0;j=0;
    while(first<=last)
    {
      if(k<n && j<m )
      {
        if(suba1[k]<suba2[j])
            a[first++]=suba1[k++];
        else a[first++]=suba2[j++];
      }

      else if(k==n)
          a[first++]=suba2[j++];
       else  a[first++]=suba1[k++];

    }

}


void mergesort(int a[], int first, int last)
  {
     if(last!=first)   // upto last 2 elements
      {
      int mid= (first +last)/2;
      mergesort(a,first,mid);
      mergesort(a,mid+1,last);
      Merge(a,first,mid,last);

      }
  }

int main()
 {cout<<"Enter the total number of elements:\n";
  int t;
  cin>>t;

  int a[t];
   cout<<"Enter the elements you want to sort:\n";
  for(int i=0;i<t;i++)
    cin>>a[i];

  mergesort(a,0,t-1);
 cout<<"\nSorted sequence: ";
  for(int i=0;i<t;i++)
    cout<<a[i]<<" ";
 return 0;
 }
