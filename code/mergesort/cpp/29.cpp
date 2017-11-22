#include<iostream>
#include<stdio.h>
#include<stdlib.h>


using namespace std;


void merge(int arr[],int l, int m, int r)
{
  int n1=m-l+1;
  int n2=r-m;

  int L[n1], R[n2];
  for(int i=0;i<n1;i++)
    {
      L[i]=arr[l+i];
    }
  for(int j=0;j<n2;j++)
    {
      R[j]=arr[m+1+j];
    }

  int i=0;
  int j=0;
  int k=l;

  while((i<n1)&&(j<n2))
    {
      if(L[i]<=R[j])
	{
	  arr[k]=L[i];
	  i++;
	}
      else
	{
	  arr[k]=R[j];
	  j++;
	}
      k++;
    }
  while(i<n1)
    {
      arr[k]=L[i];
      i++; k++;
    }
  while(j<n2)
    {
      arr[k]=R[j];
      j++; k++;
    }
}

void mergeSort(int arr[],int l, int r)
{
  if(l<r)
    {
      int m=(l+r)/2;
      mergeSort(arr,l,m);
      mergeSort(arr,m+1,r);
      merge(arr,l,m,r);
    }
}

int main()
{
  int a[100];
  //randomize();
  cout<<"\nBefore sort :"<<endl;
  for(int i=0;i<100;i++)
    {
      
      a[i]=rand()%500;
      cout<<a[i]<<" ";
    }
  mergeSort(a,0,100);
  cout<<"\nAfter sort :"<<endl;
  for(int i=0;i<100;i++)
   {
     cout<<a[i]<<" ";
   }
}
