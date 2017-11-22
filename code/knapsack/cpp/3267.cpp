#include<iostream>
using namespace std;
int ks(int C,int w[],int **tb,int v[],int n,int i)
{
	if(i>n)
	{
		tb[C][i]=0;
		return tb[C][i];		
	}
	if(w[i]>C)
	{
		if(tb[C][i+1]==0)
		{
			tb[C][i+1]=ks(C,w,tb,v,n,i+1);
			return tb[C][i+1];			
		}
	}
	else
	{
		if(tb[C][i+1]==0)
		tb[C][i+1]=ks(C,w,tb,v,n,i+1);
		if(tb[C-w[i]][i+1]==0)
		tb[C-w[i]][i+1]=ks(C-w[i],w,tb,v,n,i+1);	
		return max(tb[C][i+1],v[i]+tb[C-w[i]][i+1]);
	}
}
int main()
{
	int tb[50][50]={0};
	int n,c,w[50],v[50],i,j=1;
	cin >>n;
	cin>>c;
	for(i=0;i<n;i++)
	{
		cin>>w[i]>>v[i];
		
	}
	cout <<ks(c,w,tb,v,n,j);
	
	return 0;
}
