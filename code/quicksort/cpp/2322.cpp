#include <iostream>
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
int partition(int arr[], int low, int high)
{
  int flag=arr[low];
  while(low<high)
  {
    while(low<high&&arr[high]>=flag) 
    {
      high--;
    }
    swap(arr[low],arr[high]);
    while(low<high&&arr[low]<=flag)
    {
      low++;
    }
    swap(arr[low],arr[high]);
  }
  print(arr,MAX_LENGTH);
  cout<<low<<" "<<high<<" "<<endl;
  return high;
}

void quicksort(int arr[],int low,int high)
{
  if(low<high)
  {
  int middle=partition(arr,low,high);
  quicksort(arr,low,middle-1);
  quicksort(arr,middle+1,high);
  }
}
void main(int argc, char* argv[])
{
  int arr[MAX_LENGTH]={9,5,7,8,3,6,44,55,1,2};
  print(arr,MAX_LENGTH);
  quicksort(arr,0,MAX_LENGTH-1);
  print(arr,MAX_LENGTH);
}