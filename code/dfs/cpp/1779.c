#include<iostream>
using namespace std;


void DFS(struct Graph *G,int u,int *Visited)
{
	cout<<u<<endl;
	Visited[u]=1;
	for(int v=0;v<G->V;v++)
	{
		if(!Visited[v] && G->Adj[u][v])
			DFS(G,v,Visited);
	}
}


void DFSTraversal(struct Graph *G,int *Visited)
{
	//Initilize all the vertex as unvisited
	for(int i=0;i<G->V;i++)
		Visited[i]=0;

	for(int i=0;i<G->V;i++)
		if(!Visited[i])
			DFS(G,i,Visited);

}




