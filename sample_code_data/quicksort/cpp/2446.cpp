#include<iostream>
#include<algorithm>
#include<exception>
using namespace std;
int RandomInRange(int start,int end)
{
	return start+rand()%(end-start+1);
}
int partition(int data[],int length,int start,int end)
{
	if(data==NULL||length==0||start>end)
	
		throw new exception();
//	int index=RandomInRange(start,end);
	int index=start+rand()%(end-start+1);
	cout<<index<<":"<<data[index]<<endl;
	swap(data[index],data[end]);
	int small=start-1;
	for(int i=start;i<end;i++)
		if(data[i]<data[end])
		{
			small++;
			swap(data[i],data[small]);
		}
	small++;
	swap(data[small],data[end]);
	cout<<"small:"<<small<<endl;
	return small;
}
int partition1(int data[],int length,int start,int end)
{
        if(data==NULL||length==0||start>end)
                throw new exception();
        int index=start+rand()%(end-start+1);
	cout<<"the input data is:";
	for(int i=start;i<=end;i++)
	cout<<data[i]<<" ";
	cout<<endl;
        cout<<index<<":"<<data[index]<<endl;
        swap(data[index],data[end]);
	for(int i=start;i<=end;i++)
	cout<<data[i]<<" ";
	cout<<endl;
	int i=start;
	int j=end-1;
	while(i<j)
		{
			while(data[i]<=data[end]&&i<end)
				i++;
			while(data[j]>=data[end]&&j>start)//这里加=号；如果数组中有许多重复的元素，可以防止元素被分到一边，这是partition1相对于partition的优点
				j--;
			if(data[i]>data[end]&&data[j]<data[end]&&i<j)
			{
				swap(data[i],data[j]);
				cout<<"swap:"<<data[i]<<" "<<data[j]<<endl;
			}
			
		}
	if(data[i]>data[end])
	swap(data[i],data[end]);
	cout<<"after partition1:";
	for(int i=start;i<=end;i++)
		cout<<data[i]<<" ";
	cout<<endl;
	cout<<"i:"<<i<<endl;
	return i;

}
void quicksort(int data[],int length,int start,int end)
{
	if(start==end)
		return;
	int index=partition1(data,length,start,end);
	if (index>start)
		quicksort(data,length,start,index-1);
	if(index<end)
		quicksort(data,length,index+1,end);
	return;
}
int main()
{
	int A[]={0,4,5,6,5,5,5,3,10,11};
	int A1[]={0,4,5,3,2,8};
	int A2[]={0,2,3};
	cout<<"the data original:";
	for(int i=0;i<10;i++)
		cout<<A[i]<<" ";
	cout<<endl;
	quicksort(A,10,0,9);
//	partition1(A,10,0,9);
	cout<<"the data after quick sort:";
	for(int i=0;i<10;i++)
		cout<<A[i]<<" ";
	cout<<endl;
}
