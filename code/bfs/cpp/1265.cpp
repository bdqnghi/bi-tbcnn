#include<iostream>
#include<queue>
#include<list>
#include<vector>

using namespace std;


void BFS(vector<int> *adj,int num,int st){
	bool visited[num];
	memset(visited,false,sizeof(visited));
	visited[st]=true;
	queue<int> que;;
	que.push(st);
	vector<int> :: iterator  i;
	while(!que.empty()){
		st = que.front();
		cout<<st<<endl;
		que.pop();
		for( i = adj[st].begin() ; i!=adj[st].end() ; i++){
			if(!visited[*i]){
				visited[*i]=true;
				que.push(*i);
			}
		}
	}
}
int main(){
	int num;
	cout<<"Enter number of vertices: ";
	cin>>num;
	vector<int> *adj = new vector<int>[num];
	int i,edges;
	cout<<"Enter number of edges: ";
	cin>>edges;
	cout<<endl<<"<---Note : Name your nodes from 0 to n-1 and enter all egdes one by one: --->\n";
	for(i=0 ; i<edges ; i++){
		int j,k;
		cin>>j>>k;
		adj[j].push_back(k);
	}
	cout<<"\nStarting vertex? : ";
	cin>>i;
	BFS(adj,num,i);
}
