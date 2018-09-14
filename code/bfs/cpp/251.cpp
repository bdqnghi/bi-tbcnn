/*

 * BFS.cpp
 *
 *  Created on: Sep 16, 2015
 *      Author: user

#include<queue>
#include <iostream>
using namespace std;

void transpose(vector<int> *v,int N){
	vector<int>::iterator it;
	vector<int> vTrans[N+1];
	cout<<"Fining transpose "<<endl;
	for(int i=1;i<=N;i++){
		for(it=v[i].begin();it!=v[i].end();it++){
			vTrans[*it].push_back(i);
		}
	}

	for(int i=1;i<=N;i++){
			for(it=vTrans[i].begin();it!=vTrans[i].end();it++){
				cout<<i<<" "<<*it<<endl;
			}
		}
}
void bfs(vector<int> *v,int N){
	queue<int> q;
	bool *visited=new bool[N+1];
	for(int i=1;i<=N;i++){
		visited[i]=false;
	}
	cout<<"created visited array "<<endl;
	q.push(1);
	while(!q.empty()){
		int top=q.front();
		q.pop();
		visited[top]=true;
		cout<<top<<" ";
		vector<int>::iterator it;
		for(it=v[top].begin();it!=v[top].end();it++){
			if(visited[*it]==false){
				visited[*it]=true;
				q.push(*it);
			}
		}
	}
}
int main(){
	int N,M,src,dest;
	cin>>N>>M;
	vector<int> v[N+1];
	cout<<"Vector size "<<v->size();
	for(int i=0;i<M;i++){
		cout<<"Enter "<<(i+1)<<"edge"<<endl;
		cin>>src>>dest;
		v[src].push_back(dest);
	}

	bfs(v,N);
	transpose(v,N);
}


*/
