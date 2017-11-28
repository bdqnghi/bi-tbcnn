#include<iostream>
using namespace std;
template<class bub>
void bubble(bub arr[],int n)
{
	cout<<"\nBefore Sorting:\n";
	for(int k=0;k<n;k++)
		cout<<arr[k]<<"\t";
	for(int i=0;i<n-1;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(arr[i]>arr[j])
			{
				bub temp;
				temp=arr[i];
				arr[i]=arr[j];
				arr[j]=temp;
			}
		}
	}
	cout<<"\nAfter Sorting:\n";
	for(int k=0;k<n;k++)
		cout<<arr[k]<<"\t";
	cout<<"\n";
}

int main()
{
	int n,g,arr[20];
	float ar[20];
	char a[20];
	cout<<"Enter number of integer elements:";
	cin>>n;
	cout<<"Enter the elements:";
	for(int i=0;i<n;i++)
		cin>>arr[i];
	bubble(arr,n);
	cout<<"Enter number of float elements:";
	cin>>n;
	cout<<"Enter the elements:";
	for(int i=0;i<n;i++)
		cin>>ar[i];
	bubble(ar,n);
	cout<<"Enter number of cahracters:";
	cin>>n;
	cout<<"Enter the elements:";
	for(int i=0;i<n;i++)
		cin>>a[i];
	bubble(a,n);
	return 0;
}
