#include <iostream>
#include <vector>
#include <iterator>
#include <string>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <iomanip>
#include <numeric>
using namespace std;


void bubbleSort(int arr[],int n)
{
	int swa[n]={0};
	for(int i=0;i<n-1;i++)
	{
		for(int j=1;j<n-i;j++)
		{
			if(arr[j-1]>arr[j])
			{
				int temp=swa[j-1];
				swa[j-1]=swa[j]+1;
				swa[j]=temp+1;
				swap(arr[j-1],arr[j]);
			}
		}
	}
	cout<<"Number of swaps : ";
	for(int i=0;i<n;i++)
	{
		cout<<swa[i]<<" ";
	}
	cout<<endl;
}

int main()
{
	//int n=8;
	//int arr[]={23,65,43,78,21,86,34,69};
	int n=5;
	int arr[]={3,2,4,1,5};
	cout<<"Before Sorting the array : ";
	for(int i=0;i<n;i++)
	{
		cout<<setw(4)<<arr[i]<<" ";
	}
	cout<<endl;
	bubbleSort(arr,n);
	cout<<"After  Sorting the array : ";
	for(int i=0;i<n;i++)
	{
		cout<<setw(4)<<arr[i]<<" ";
	}
	cout<<endl;
	return 0;
}