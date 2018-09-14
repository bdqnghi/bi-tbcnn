#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<string>


using namespace std;
int max( int a , int b)
{
	if (a>b)
	return a;
	
	return b;
}
void prin(int **a,int r,int c)
{
	for(int i=0;i<r;i++)
		{
			for(int j=0;j<c;j=j+1)
			cout<<a[i][j];
			
			cout<<endl;
		}
		
		cout<<endl;
}

int main()
{
	int w[] = {1,3,4,5};
	int v[] = {1,4,5,7};
	int kp;
	cin>>kp;
	
	int sw = sizeof(w)/4;
	
	int **a= new int* [sw];
	
	for(int i=0;i<sw;i++)
	{
		*(a+i) = new int[kp+1];
		a[i][0]=0;
	}
	cout<<"mmm\n";
	
	
	for(int i=0; i< sw; i++)
	for(int j=1;j<=kp;j++)
	{
		if( j >= w[i] )
		{
			if(i > 0)
			{
				a[i][j] = max(a[i-1][j-w[i]]+v[i],a[i-1][j]) ;
			}
			
			else{
			a[i][j] = v[i]; 
			}
		}	
		else
		{
				if(i > 0)
				{
					a[i][j] = a[i-1][j] ;
				}
			
				else{
				a[i][j] = 0; 
				}
		}	
	}
	
	//cout<<a[sw-1][kp];	
	prin(a,sw,kp+1);
	return 0;
}
