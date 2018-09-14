#include<iostream>
#include<queue>
#include<vector>
#include<string.h>
using namespace std;

int main()
{
	int E,s,d,V;
	cin>>V;
	vector<vector<int> >v(V);
	cout<<"\nEnter the no. of Edges..";
	cin>>E;
	cout<<"\nEnter the edge verices line by line..";
	for(int i=0;i<E;i++)
	{
		cin>>s>>d;
		v[s].push_back(d);
		//v[d].push_back(s);
	}
	//BFS
	queue<int> q;
	bool visited[V];
	memset(visited,false,V);
	cout<<"Enter the start vertex..";
	cin>>s;
	visited[s]=true;
	q.push(s);
	while(!q.empty())
	{
		s=q.front();
		cout<<s<<"->";
		q.pop();
		for(int i=0;i<v[s].size();i++)
		{
			if(visited[v[s][i]]==false)
			{
				visited[v[s][i]]=true;
				q.push(v[s][i]);
			}
		}
	}
	return 0;
}
