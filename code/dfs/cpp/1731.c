#include <iostream>
#include <stack>
#include <algorithm>
#include <vector>
#include <string.h>
using namespace std;

void addEdge(vector<int>* adj,int i,int j){ //adjacency list
        adj[i].push_back(j);
}

void DFSUtil(vector<int>* adj,int v,bool *visited){
	visited[v]=true;
	cout<<v<<" ";
	for(int i=0;i<adj[v].size();++i){
		if(!visited[adj[v][i]])
			DFSUtil(adj,adj[v][i],visited);
	}
}

void DFS(vector<int>* adj,int n,int start=0){
	bool visited[n];
	memset(visited,false,sizeof(bool)*n);
	//handling a disconnected graph
	/*
	for(int i=0;i<n;++i){
		if(!visited[i]){
			DFSUtil(adj,i,visited);
		}
	}
	*/
	//End at the connected component of the graph containing "start"
	DFSUtil(adj,start,visited);
}



int main(){
	int n=4;
	vector<int> adj[n];
	addEdge(adj,0,1);
	addEdge(adj,0,2);
	addEdge(adj,1,2);
	addEdge(adj,2,0);
	addEdge(adj,2,3);
	addEdge(adj,3,3);
	DFS(adj,n,2);
	return 0;
}
