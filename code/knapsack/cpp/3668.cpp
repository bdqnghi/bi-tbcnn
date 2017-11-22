/*Implement 0/1 Knapsack problem using Dynamic Programming. */

#include <iostream>
using namespace std;

int max(int a,int b)
{
	return a>b?a:b;
}
class knapsack
{
	int n;			//Number of objects
	int m;			//Capacity of the knapsack
	int v[10][10];		//Solution table
	int p[10];		//Porfit table
	int w[10];		//Weights table
public:
	void read_data();
	void optimal_solution();
	void write_data();	
};

void knapsack::read_data()
{
	cout<<"Enter the number of objects"<<endl;
	cin>>n;

	cout<<"Enter the weights and profit of the objects"<<endl;
	for (int i = 1; i <= n; i++)
		cin>>w[i]>>p[i];

	cout<<"Enter the Capacity of the knapsack"<<endl;
	cin>>m;
}

void knapsack::write_data()
{
	cout<<"The Output is"<<endl;
	for (int i=0; i<=n; ++i)
	{
		for(int j=0;j<=m;j++)	cout<<v[i][j]<<" ";
		cout<<endl;
	}
	cout<<"The optimal solution is "<<v[n][m]<<endl;
}

void knapsack::optimal_solution()
{
	for(int i=0;i<=n;i++)
		for(int j=0;j<=m;j++)
		{
			if(i==0 || j==0) v[i][j]=0;
			else if(j<w[i])  v[i][j]=v[i-1][j];
			else		 v[i][j]=max(v[i-1][j],v[i-1][j-w[i]]+p[i]);
		}
}

int main()
{
	knapsack a;
	a.read_data();
	a.optimal_solution();
	a.write_data();
}
