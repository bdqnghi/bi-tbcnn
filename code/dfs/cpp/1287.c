/*
TEST CASE 
6

0 1
0 2
2 1
1 3
3 2
4 3
5 5
-1 -1
*/

#include <iostream>
#include <cstring>
#include <vector>

#define INF -1

using namespace std;

class Graph
{
	int N;
	vector<vector<int> > G;
	vector<int> dist;	//distance from root
	vector<int> dt;		//discovery time
	vector<int> ft;		//finish time
	
	public:
	Graph(int n)
	{
		this -> N = n;
		for(int i = 0; i < N; i++)
		{
			dist.push_back(INF);
			vector<int> temp;
			for(int j = 0; j < N; j++)
				temp.push_back(0);
			G.push_back(temp);
		}
	}
	
	void addEdge(int i, int j);
	void DFS(int source);
	void DFS_visit(int node, bool visited[]);
	void printResult(void);
};

void Graph::addEdge(int i, int j)
{
	G[i][j] = 1;
	return;
}

void Graph::DFS(int s)
{
	bool *visited = new bool[N];
	for(int i = 0; i < N; i++)
		visited[i] = false;
	
	dist[s] = 0;
	DFS_visit(s, visited);
}

void Graph::DFS_visit(int s, bool visited[])
{
	visited[s] = true;
	
	for(int i = 0; i < N; i++)
	{
		if(G[s][i] && !visited[i])
		{
			dist[i] = dist[s] + 1;
			DFS_visit(i, visited);
		}
	}
}

void Graph::printResult()
{
	cout << "Distances are" << endl;
	for(int i = 0; i < N; i++)
		cout << dist[i] << endl;
}

int main()
{
	int n;
	cout << "Enter num of vertex" << endl;
	cin >> n;

	Graph g(n);
	
	cout << "Enter the edges.. write -1 -1 to quit" << endl;
	int x , y;
	cin >> x >> y;
	while(x != -1)
	{
		g.addEdge(x, y);
		cin >> x >> y;
	}

	cout << endl << "Enter source";
	int source;
	cin >> source;
	g.DFS(source);
	g.printResult();

	return 0;
}
