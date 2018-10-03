#include<stdio.h>
int a[1000006],heap[1000006];
int n,k,m,flag;
int fun(int a,int b)
{
	return flag^(b-a>0); //...//some problem
}
void shiftdown(int l)
{
	int i,j;
	i=l;
	j=2*i;
	heap[0]=heap[i];
	while(j<=m)
	{
		if(j<m&&fun(a[heap[j]],a[heap[j+1]])) j++;
		if(fun(a[heap[0]],a[heap[j]]))
		{
			heap[i]=heap[j];
			i=j;
			j=2*i;
		}
		else 
		{
			heap[i]=heap[0];
			return ;
		}
	}
	heap[i]=heap[0];
}

void shiftup(int l)
{
	int i,j;
	heap[0]=heap[l];
	i=l;
	j=i/2;
	while(j>=1)
	{
		if(fun(a[heap[j]],a[heap[0]]))
		{
			heap[i]=heap[j];
			i=j;
			j=i/2;
		}
		else
		{
			heap[i]=heap[0];
			return ;
		}
	}
	heap[i]=heap[0];
}
void max()
{
	int i;
	m=k;
	for(i=1;i<=k;i++) heap[i]=i;
	for(i=k/2;i>=1;i--) shiftdown(i);
	printf("%d",a[heap[1]]);
	for(i=k+1;i<=n;i++)
	{
		heap[++m]=i;
		shiftup(m);
		heap[0]=heap[1];
		while(heap[0]<=i-k)
		{
			heap[1]=heap[m--];
			shiftdown(1);
			heap[0]=heap[1];
		}
		printf(" %d",a[heap[0]]);
	}
	printf("\n");
}
int main()
{
	int i;
	while(scanf("%d%d",&n,&k)!=EOF)
	{
		for(i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
		}
		flag=1;
		max();
		flag=0;
		max();
	}
	return 0;
}
