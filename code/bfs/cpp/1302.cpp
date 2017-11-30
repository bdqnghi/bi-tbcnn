/*
BFS

O(V+E) if Adjacency List is used
O(V^2) if Adjacency Matrix is used
*/
void bfs(int s, vector<int> g[], bool vis[])
{
    queue <int> q;
    q.push(s);
    vector<int>::iterator it;
    while(!q.empty()){
        int child = q.front();
        q.pop();
        vis[child] =true;
        printf("%d ",child);
        for(it= g[child].begin();it<=g[child].end()-1;++it)
            if(!vis[*it])
                q.push(*it);
    }
}