#include <iostream>

using namespace std;


long long int iterations=0;
long long int comparisons=0;
long long int functionCalls=0;

void insertSort(int *a,int n)
{
	for (int i=1; i<n; ++i)
	{
		iterations++;
		int t=a[i];
		int k;
		comparisons++;
		for (k=i-1; (k>=0)&&(a[k]>t); k--)
		{
			iterations++;
			comparisons++;
			a[k+1]=a[k];
		}
		a[k+1]=t;
	}
}

void merge(int *t, int  *u, int *v, int n)
{
	int j=0, k=0;
	//showArray(u,n/2);
	//showArray(v,(n+1)/2);
	for (int i=0; i<n; i++)
	{
		iterations++;
		comparisons++;
		if (j<n/2)
		{
			comparisons++;
			if (k<(n+1)/2)
			{
				comparisons++;
				if (u[j]<=v[k]) { t[i]=u[j]; j++; }
				else  { t[i]=v[k]; k++; }
			}
			else 
			{
				t[i]=u[j]; j++;
			}
		}
		else 
		{
			t[i]=v[k]; k++;
		}
	}
}

void mergeSort(int *t,int n)
{
	functionCalls++;
	if (n<=16)
	{
		insertSort(t,n);
	}
	else
	{
		int *u=new int[n/2];
		int *v=new int[(n+1)/2];
		for (int i=0; i<n; i++)
		{
			iterations++;
			comparisons++;
			if (i<n/2) u[i]=t[i];
			else v[i-n/2]=t[i];
		}
		mergeSort(u,n/2);
		mergeSort(v,(n+1)/2);

		merge(t,u,v,n);
	}
}

int main ()
{
	int n;
	cout << "Give n:"<<endl;
	cin >> n;

	int *a=new int[n];

	for (int i=n-1; i>=0; i--)
	{
		a[i]=i;//rand()%100000;
		//cout <<" "<< a[i];
	}
	cout << endl;
	mergeSort(a,n);
	cout << "Done;"<<endl;
	cout << " iterations: "<<iterations<<" comparisons: "<<comparisons<<" function calls: "<<functionCalls ;
	//showArray(a,n);
	
	return 0;
}
