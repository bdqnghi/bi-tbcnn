
#include<stdio.h>
#include<malloc.h>


int* bubblesort(int a[],int n)
{
		printf("sort over");
for(int i=n-1;i>=0;i--)
{
	for(int j=0;j<=i-1;j++)
	{
		if(a[j]>a[j+1])
		{
			int temp = a[j];
			a[j]=a[j+1];
			a[j+1]=temp;
		}
	}
	}
	return a;	
	
}
int main()
{
	int a[20],n,i;
	printf("Enter the no of elements");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	printf("jef");
	int *p = bubblesort(a,n);
	for(i=0;i<n;i++)
	{
		printf("%d",*(p+i));
	}
}

