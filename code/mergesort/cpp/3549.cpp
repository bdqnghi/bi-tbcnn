#include <iostream>
#include <vector>
using namespace std;
#define MAX_LENGTH 10

void print(int arr[],int length)
{
    for(int i=0;i<length;i++)
    {
        cout<<arr[i]<<"\t";
    }
    cout<<endl;
}
void swap(int &a,int &b)
{
  int temp=a;
  a=b;
  b=temp;
}
void merge(int sorted[], int arr[], int start,int middle,int end)
{
  int i=start;
  int j=middle+1;
  int k=start;
  while(i<=middle&&j<=end)
  {
    if(arr[i]>arr[j])
    {
      sorted[k]=arr[j];
      k++;
      j++;
    }
    else
    {
      sorted[k]=arr[i];
      k++;
      i++;
    }
  }

  for(;i<=middle;i++)
  {
    sorted[k]=arr[i];
    k++;
  }
  for(;j<=end;j++)
  {
    sorted[k]=arr[j];
    k++;
  }
}
void mergesort(int arr[],int sorted[],int start,int end)
{
  int tmp[MAX_LENGTH];
  if(start==end)
    sorted[start]=arr[start];
  else
  {
    int middle=(start+end)/2;
    mergesort(arr,tmp,start,middle);
    mergesort(arr,tmp,middle+1,end);
    merge(sorted,tmp,start,middle,end);
  }
 // print(sorted,MAX_LENGTH);
}

void main(int argc, char** argv)
{
  int arr[MAX_LENGTH]={9,5,7,8,3,6,44,55,1,2};
  int sorted[MAX_LENGTH];
  print(arr,MAX_LENGTH);
  mergesort(arr,sorted,0,MAX_LENGTH-1);
  print(sorted,MAX_LENGTH);

}