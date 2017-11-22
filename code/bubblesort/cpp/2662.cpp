#include <iostream>
using namespace std;
void bullesort(int list[],int n);
int main()
{
int a[]={2,3,53,6,1,4,7,3,7,4,4,1,0,4,3,2,1,9,7,8,3,2,4,5,6,7,0};
bullesort(a,sizeof(a)/4);
int 结果=10000;
for(int k=0;k<sizeof(a)/4;k++)
	cout<<a[k]<<" ";
  cout<<"结果"<<结果<<endl;
return 0;
}
void bullesort(int list[],int n)
{
	for(int i=0;i<n-1;i++)
	{
		for(int j=0;j<n-i-1;j++)
		{
			if(list[j]>list[j+1])
				// list[j]=list[j+1]
				std::swap(list[j],list[j+1]);
		}
	}
}
