/*
 * For O(logn), competition of Tower Research
 * This algorithm is a Depth First Search algo on a graph represented 
 * in the standard way of vertex list and an edge list
 */

#include <stdlib.h>
#include <stdio.h>
#include <vector>

#define INF 10000000

using namespace std;

int minCost = INF;

void dfs (int cur, int target, bool *visited, int curPath, vector< pair <int,int> > *vertexList)
{
	if (cur == target)
	{
		if (minCost > curPath)
			minCost = curPath;
		return;
	}

	visited[cur] = true;
	for (auto it = vertexList[cur].begin(); it != vertexList[cur].end(); ++it) {
		int v = it->first;
		int w = it->second;
		// DEBUG: Print out v and w just to check!!!!
		if (!visited[v]) {
			dfs(v, target, visited, curPath+w, vertexList);
		}
	}
	visited[cur] = false; // Cleanup
}
	
	
	
int main()
{
	int T;
	scanf("%d",&T);
	int source,target;
	for (int i=0; i<T; i++)
	{
		int numVert, numEdges;
		scanf("%d %d", &numVert, &numEdges);
		vector < pair<int,int> > vertexList[numVert];
		for (int j=0; j<numEdges; j++)
		{
			int u,v,w;
			scanf("%d %d %d", &u, &v, &w);
			vertexList[u].push_back(pair<int, int>(v, w));
		}
		//Graph Complete
		int Q;
		scanf("%d",&Q);
		
		for (int j=0; j<Q; j++)
		{
			minCost = INF;
			bool visited[numVert];
			for (int j=0; j<numVert; j++)
				visited[j] = false;
		
			int cost, source, target;
			scanf("%d %d", &source, &target);
			dfs (source, target, visited, 0, vertexList);
			printf("%d\n", minCost);
		}
	}
	return EXIT_SUCCESS;
}
