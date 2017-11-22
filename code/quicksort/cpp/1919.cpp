#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
void swap(int *a,int *b){
	int tmp=*a;*a=*b;*b=tmp;
}
void quicksort(int *num,int first,int last);
int partition(int *num,int first,int last);
int main()
{
	int number;
	cin>>number;
	int *numSort=new int[number+1];
	int i;
	for(i=1;i<=number;i++)
		cin>>numSort[i];
	quicksort(numSort,1,number);
	for(i=1;i<=number;i++)
		cout<<numSort[i]<<" ";
	cout<<endl;
	delete[] numSort;
	return 0;
} 
void quicksort(int *num,int first,int last)
{
	if(first<last)
	{
		int position=partition(num,first,last);
		quicksort(num,first,position-1);
		quicksort(num,position+1,last);
	}
}
int partition(int *num,int first,int last)
{
	srand((unsigned)time(NULL));
	int random = rand()  % (last - first + 1) + first;
	int p = first;
	swap(num[random],num[last]);
	for(int i=first;i!=last;i++)
		if(num[i]<num[last])
		{
			swap(num[p],num[i]);
			p++;
		}
	swap(num[p],num[last]);
	return p;
}
