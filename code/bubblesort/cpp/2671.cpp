#include<iostream>
using namespace std;
void BubbleSort(int A[],int n);
int main()
{
	int array[]={34,65,12,43,67,5,78,10,3,70};
	int len=sizeof(array)/sizeof(int);
	cout<<"The orginal array size is:"<<endl;
	for(int i=0;i<len;i++)
		cout<<array[i]<<",";
	cout<<endl;
	BubbleSort(array,len);
        cout<<"The sorted array size is:"<<endl;
        for(int i=0;i<len;i++)
                cout<<array[i]<<",";
        cout<<endl;
	return 0;
}
void BubbleSort(int A[],int n)
{
	bool sorted = false;
	while (!sorted)
	{
		sorted = true;
		for (int i=1; i<n;i++)
		{
			if ( A[i-1] > A[i] )
			{
				swap(A[i-1],A[i]);
				sorted=false;
			}
		}
	n--;
	}
}
