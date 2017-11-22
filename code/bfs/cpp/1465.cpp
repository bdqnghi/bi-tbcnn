#include<iostream>
#include<queue>
using namespace std;
class graph
{
	int matrix[10][10],tree[10][10];
	int n;
	public:
		graph()
		{
			cout<<"\nEnter the number of vertices:";
			cin>>n;
			for(int i=0;i<=n;i++)
			for(int j=0;j<=n;j++)
			{
				matrix[i][j]=0;
				tree[i][j]=0;
			}
		}
		void create_graph();
		void display();
		void bfs(int);
};
void graph::bfs(int s)
{
	int a;
	int v[10];
	for(int i=0;i<=n;i++)
	v[i]=0;
	v[s]=1;
	queue<int> q;
	q.push(s);
	while(!q.empty())
	{
		a=q.front();
		q.pop();
		for(int i=0;i<=n;i++)
		if(matrix[a][i]!=0&&v[i]==0)
		{
			v[i]=1;
			tree[a][i]=1;
			q.push(i);
		}
	}
}
void graph::create_graph()
{
	int k,a,b;
	cout<<"\nEnter the number of edges:";
	cin>>k;
	for(int i=0;i<k;i++)
	{
		cout<<"\nEnter the edges:";
		cin>>a>>b;
		matrix[a][b]=1;
		matrix[b][a]=1;
	}
}
void graph::display()
{
	cout<<"\nThe adjacency matrix is:";
	for(int i=1;i<=n;i++)
	{
	cout<<"\n";
	for(int j=1;j<=n;j++)
	cout<<"\t"<<matrix[i][j];
    }
	cout<<"\nThe resultant matrix is:";
	for(int i=1;i<=n;i++)
	{
	cout<<"\n";
	for(int j=1;j<=n;j++)
	cout<<"\t"<<tree[i][j];
    }
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	if(tree[i][j]==1)
	cout<<"\n"<<i<<"----->"<<j;
}
int main()
{
	graph g;
	g.create_graph();
		g.bfs(1);
	g.display();

}
