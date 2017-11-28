#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void addEdge(vector < vector <bool> > &graph, int noVert, int i, int j)
{
	graph[i][j]=1;
	graph[j][i]=1;
}

bool isNeighbor(vector < vector <bool> > &graph, int noVert, int i, int j)
{
	return graph[i][j] || graph[j][i];
}

void bfs(vector < vector <bool> > &graph, int noVert, int startVert)
{
	vector < bool > visited(noVert);
	queue <int> bfq;
	bfq.push(startVert);
	visited[startVert]=1;
	int level=0;
	while (! bfq.empty())
	{
		int curVert = bfq.front();
		bfq.pop();
		if (!visited[curVert]) {
			cout << curVert<< " ";
			visited[curVert] = 1;
		}
		else 
			level++;
		for (int i=0; i<noVert; i++)
			if (isNeighbor(graph, noVert, curVert, i))
					if (!visited[i])
						bfq.push(i);
	}
	cout << "No. of levels: "<<level;
}

int main()
{
	int n;
	cout << "Enter the number n of vertices: ";
	cin >> n;
	vector< vector <bool> > graph(n, vector<bool> (n, 0));
	for (int firstVert=0; firstVert<n; firstVert++)
	{
		cout << "Enter the number of neighbours of vertex "<<firstVert<<" : ";
		int noNeighbors;
		cin >> noNeighbors;
		for (int i=0; i<noNeighbors; i++)
		{	int secondVert;
			cin >> secondVert;
			if (secondVert < n && secondVert >=0)
				addEdge(graph, graph.size(), firstVert, secondVert);
		}
	}
	int startVert;
	cin >> startVert;
	bfs(graph, graph.size(), startVert);
}
