#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstdlib>
#include<queue>
using namespace std;

vector<int>G[100];

void bfs(int src, int des)
{
    queue<int>Q;
    int visited[100],level[100],parent[100];
    int u,v,i;

    Q.push(src);
    visited[src]=1;
    level[src]=0;

    while(!Q.empty())
    {
        u= Q.front();
        for(i=0;i<G[u].size();i++)
        {
            v= G[u][i];
            if(!visited[v])
            {
                level[v]=level[u]+1;
                visited[v]=1;
                parent[v]=u;
                Q.push(v);
            }
        }
        Q.pop();
    }
    printf("The distance between %d and %d is %d\n",src,des,level[des]);
}

int main()
{
    int n,e,i,x,y;
    printf("%d",-17%5);
    scanf("%d %d",&n,&e);

    for(i=0;i<e;i++)
    {
        scanf("%d %d ",&x,&y);

        G[x].push_back(y);
        G[y].push_back(x);
    }
    bfs(1,3);
    return 0;
}

