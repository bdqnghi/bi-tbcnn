#include<iostream>
#include<queue>
using namespace std;
/************************Class Graph*************************/
class Graph
{
   int** matrix;
   int** tree,*v;
   int vertices;
public:
   void bfs(int s);
   void create_graph();
   void display();
   Graph();
};
/************************constructor*************************/
Graph::Graph()
{
     cout<<"\nEnter the number of vertices:";
     cin>>vertices;
     matrix = new int*[vertices+1];
     tree = new int*[vertices+1];
     v= new int[vertices+1];
     for(int i = 0; i <=vertices;i++)
      {
      matrix[i]=new int[vertices+1];
      tree[i]=new int[vertices+1];
      }
     for(int i = 0; i <=vertices;i++)
     for(int j=0;j<=vertices;j++)
      {
       tree[i][j]=0;
       matrix[i][j]=0;
       v[i]=0;
      }
}
/************************bfs*************************/
void Graph::bfs(int s)
{
  int a;
queue<int> q;
q.push(s);
v[s]=1;
  while(!q.empty())
  {
  	a=q.front();
  	q.pop();
  	for(int i=1;i<=vertices;i++)
     if(matrix[a][i]!=0)
     if(v[i]==0)
     {
     	v[i]=1;
     	q.push(i);
     	tree[i][a]=1;
	 }
  }
}
/*******************create graph*************************/
void Graph::create_graph()
{
  int i,n,a,b;
  cout<<"Enter the number of edges:";
  cin>>n;
  for(i=0;i<n;i++)
  {
    cout<<"Enter the edges:";
    cin>>a>>b;
    matrix[a][b]=1;
    matrix[b][a]=1;
  }
}
/*********************Display graph*************************/
void Graph:: display()
{
 cout<<"\n\t";
 for(int j=1;j<=vertices;j++)
  cout<<"\t"<<j;
  cout<<"\n\n";
 for(int i=1;i<=vertices;i++)
  {
  cout<<"Vertices ["<<i<<"]:";
  for(int j=1;j<=vertices;j++)
  {
  cout<<"\t"<<matrix[i][j];
  }
  cout<<"\n";
  }
  cout<<"\nFinal tree :";
  cout<<"\n\t";
  for(int j=1;j<=vertices;j++)
   cout<<"\t"<<j;
   cout<<"\n\n";
  for(int i=1;i<=vertices;i++)
  {
    cout<<"Vertices ["<<i<<"]:";
  for(int j=1;j<=vertices;j++)
  {
    cout<<"\t"<<tree[i][j];
  }
  cout<<"\n";
  }
  cout<<"Path is \n";
  for(int i=1;i<=vertices;i++)
  for(int j=1;j<=vertices;j++)
  if(tree[i][j]==1)
  cout<<i<<"-->"<<j<<"\n";
}
/************main*************/
int main()
{
 int ch;
 Graph g;
 g.create_graph();
 cout<<"\nEnter the vertex to perform dfs:";
 cin>>ch;
 g.bfs(ch);
 g.display();
}
