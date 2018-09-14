/*

 * BFS.cpp
 *
 *  Created on: Aug 26, 2015
 *      Author: user

#include<queue>
#include <iostream>
using namespace std;
class Node{
	int data;
	Node* next;
	friend class Graph;
};
class Graph{
	int vertices;
	Node **adj;
	Node* newNode(int data);
public:
	Graph(int vertex);
	void addEdge(int src,int dest);
	void addUndirectedEdge(int src,int dest);
	void BFS(int src);
	void showGraph();
};

Graph::Graph(int v){
	this->vertices=v;
	adj=new Node*[vertices];
	for(int i=0;i<vertices;i++){
		adj[i]=NULL;
	}
}

Node* Graph::newNode(int data){
	Node* tmp=new Node();
	tmp->data=data;
	tmp->next=NULL;
	return tmp;
}

void Graph::addUndirectedEdge(int src,int dest){
	addEdge(src,dest);
	addEdge(dest,src);
}
void Graph::addEdge(int src,int dest){
	if(adj[src]==NULL){
		adj[src]=newNode(dest);
	}
	else{
		Node *tmp=newNode(dest);
		tmp->next=adj[src];
		adj[src]=tmp;
	}
}

void Graph::showGraph(){
	for(int i=0;i<vertices;i++){
		while(adj[i]){
			cout<<i<<" "<<adj[i]->data<<" "<<endl;
			adj[i]=adj[i]->next;
		}
	}
}

void Graph::BFS(int src){
	int *visited=new int[vertices];
	queue<int> q;

	for(int i=0;i<vertices;i++){
		visited[i]=0;
	}

	q.push(src);
	while(!q.empty()){
		int top=q.front();

		cout<<top<<" ";
		visited[top]=1;
		q.pop();


		Node *tmp=adj[top];
		while(tmp){
			if(visited[tmp->data]==0){

					q.push(tmp->data);
			}
			tmp=tmp->next;
		}
	}
}

int main(){
	Graph g(4);
	g.addEdge(0,1);
	g.addEdge(0,2);
	g.addEdge(1,2);
	g.addEdge(2,0);
	g.addEdge(2,3);
	g.addEdge(3,3);

	//g.showGraph();
	cout<<endl<<"BFS "<<endl;
	g.BFS(2);
}
*/
