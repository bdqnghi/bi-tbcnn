#include<iostream>
#include<vector>
#include<list>
using namespace std;

void addEdge(vector<int> adj[],int u,int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void BFS(vector<int> adj[],int v,int s)
{
    vector<bool> visited(v,false);
    list<int> queue;
    visited[s]=true;
    queue.push_back(s);
    vector<int>::iterator i;
    while(!queue.empty())
    {
        s=queue.front();
        cout<<s<<'\n';
        queue.pop_front();

        for(i=adj[s].begin();i!=adj[s].end();++i)
        {
            if(!visited[*i])
            {
                visited[*i]=true;
                queue.push_back(*i);
            }
        }
    }
}
int main()
{
    int v=5;
    vector<int> adj[v];
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 4);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 1, 4);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 4);
    BFS(adj,v,0);
}

