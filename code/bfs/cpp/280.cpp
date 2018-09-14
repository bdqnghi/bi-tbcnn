/*

 * BFS.cpp
 *
 *  Created on: Sep 2, 2015
 *      Author: user


#include<iostream>
#include<queue>
#include<list>
using namespace std;
void calculateBFS(int N,int **adj,int count[],int source){
	queue<int> q;
	q.push(source);
	int level=0;
	int *visited=new int[N+1];
	for(int i=1;i<=N;i++){
		visited[i]=0;
	}
	while(!q.empty()){
		int top=q.front();
		q.pop();

		level++;
		for(int i=1;i<=N;i++){
			if(adj[top][i]&&!visited[i]){
				visited[i]=1;
				q.push(i);

				count[i]=level*6;
			}
		}
	}

	for(int i=1;i<=N;i++){
		if(i!=source)
		cout<<count[i]<<" ";
	}
}
void createAdjacency(int  N,long long int M){
	int x,y,S;
	int **adj=new int* [N+1];
	for(int k=1;k<=N;k++){
		adj[k]=new int[N+1];
	}
	int count[N+1];
	for(int j=1;j<=N;j++){
		for(int k=1;k<=N;k++){
			adj[j][k]=0;
			count[j]=-1;
		}
	}
	for(long long int i=0;i<M;i++){
		cin>>x>>y;
		adj[x][y]=6;
		adj[y][x]=6;
	}

	cin>>S;
	calculateBFS(N,adj,count,S);

}

int main(){
	int T;
	cin>>T;
	int N;
	long long int M;
	for(int i=0;i<T;i++){
		cin>>N>>M;
		createAdjacency(N,M);
	}
}


*/
