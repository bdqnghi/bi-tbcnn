
int pivot(int arr[],int m,int n)
{
	int pivot_value=arr[m],temp,i=m,j=n+1;
	
	do	{
			do {	
				i++;
				
			   }while(arr[i] < pivot_value && i <=n);
		
			do {
				j--;	
			   }while(arr[j] > pivot_value);

			 if( i < j)
			  { 
				temp=arr[j];
				arr[j]=arr[i];
				arr[i]=temp;
			   }
			   		
		}while( i < j);
	arr[m]=arr[j];
	arr[j]=pivot_value;
	return j;
}

void quicksort(int arr_element[],int first_indx,int last_indx)
{
	if(first_indx < last_indx) {
			int pivot_pos;
			pivot_pos=pivot(arr_element,first_indx,last_indx);
			quicksort(arr_element,first_indx,pivot_pos-1);
			quicksort(arr_element,pivot_pos+1,last_indx);
		}
}


/*
#include<iostream>
using namespace std;
int main()
{
	int n,ar[101],i;
	
	cout<<"\n enter the n: ";
	cin>>n;
	
	for(i=0;i<n;i++)	cin>>ar[i];

	quicksort(ar,0,n-1);
	
	for(i=0;i<n;i++)
	{
		cout<<"	  "<<ar[i];
		
	}
	
	cout<<"\n";

	return 0;

}
*/