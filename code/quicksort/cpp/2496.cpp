#include <iostream>
#include <stdlib.h>
using namespace std;
int partition(int arr[],int start,int end)
{
	int pindex = start;
	int pivot = arr[end];
	for(int i=start;i<end;i++)
	{
		if(arr[i] <= pivot)
		{
			swap(arr[i],arr[pindex]);
			pindex++;
		}
	}
	swap(arr[pindex],arr[end]);
	return pindex;
}
int randomaizedpartition(int arr[],int start,int end)
{
	int random = start + rand( )%(end-start +1);
	swap(arr[random],arr[end]);
	return partition(arr,start,end);
}
void quicksort(int arr[],int start,int end)
{
	if(start < end)
	{
		int pindex = randomaizedpartition(arr,start,end);
		quicksort(arr,start,pindex-1);
		quicksort(arr,pindex+1,end);
	}
}
int main()
{
	int n;cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
		cin>>arr[i];
	quicksort(arr,0,n-1);
	cout<<endl;
	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";
	cout<<endl;
	return 0;
}