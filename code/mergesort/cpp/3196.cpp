#include <iostream>

using namespace std;

void merge(int *, int, int);
void mergeSort(int *, const int, const int);

void print_arr(int *, int);

int main(void)
{
	int size;

	cout<<"ũ�� �Է� : ";
	cin>>size;
	
	int *arr = new int[size];

	cout<<"ũ�� "<<size<<"�� �迭 �Է� : ";
	for(int i=0;i<size;i++)
		cin>>arr[i];
	
	print_arr(arr, size);

	mergeSort(arr, 0, size-1);
	
	print_arr(arr, size);
	
	return 0;
}

void mergeSort(int *arr, int start, int end)
{
	if(start>=end)
		return;

	int mid = (start+end)/2;
	
	mergeSort(arr, start, mid);
	mergeSort(arr, mid+1, end);
	
	merge(arr, start, end);
	
	return;
}

void merge(int *arr, const int start, const int end)
{
	int mid = (start+end)/2;
	int lptr = start;
	int rptr = mid+1;
	int *temp_arr = new int[end-start+1];
	int count = 0;
	
	while(true)
	{
		if(lptr>mid)
		{
			while(rptr<=end)
				temp_arr[count++]=*(arr+rptr++);
			break;
		}
		if(rptr>end)
		{
			while(lptr<=mid)
				temp_arr[count++]=*(arr+lptr++);
			break;
		}
		
		if(*(arr+lptr)<=*(arr+rptr))
			temp_arr[count++]=*(arr+lptr++);
		else
			temp_arr[count++]=*(arr+rptr++);
	}
	
	for(int i=start;i<=end;i++)
		*(arr+i)=temp_arr[i-start];
	
	return;
}

void print_arr(int *arr, int size)
{
	cout<<'(';
	for(int i=0;i<size;i++)
		cout<<*(arr+i)<<", ";
	cout<<'\b'<<'\b'<<')'<<endl;
}
