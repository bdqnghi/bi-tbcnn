#include<iostream>
using namespace std;
int partition(int arr[],int l,int r)
{
  int i=l-1,temp;
  for(int j=l;j<r;j++)
    if(arr[j]>arr[r])
    {
      i++;
      temp=arr[i];
      arr[i]=arr[j];
      arr[j]=temp;
    }
  temp=arr[r];
  arr[r]=arr[++i];
  arr[i]=temp;
  return i;
}
void QuickSort(int arr[],int low,int high)
{
  if(low<high)
  {
    int p=partition(arr,low,high);
    QuickSort(arr,low,p-1);
    QuickSort(arr,p+1,high);
  }
}
int main()
{
 int N;cin>>N;
 while(N--)
 {
   int n;cin>>n;
   int arr[n];
   for(int i=0;i<n;i++)cin>>arr[i];
   QuickSort(arr,0,n-1);
   for(int i=0;i<n;i++)cout<<" "<<arr[i];
   cout<<endl;
}
}