#include <algorithm>
#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
#define DFS_WHITE -1

typedef vector<int> vi;

vector<vi> AdjList;
vi dfs_num,dfs_parent,dfs_low,articulation_vertex;
int dfsNumberCounter, dfsRoot, rootChildren,V;

void articulationPointAndBridge(int u) {
  dfs_low[u] = dfs_num[u] = dfsNumberCounter++;
  for (int j = 0; j < (int)AdjList[u].size(); j++) {
    int v = AdjList[u][j];
    if (dfs_num[v] == DFS_WHITE) {
      dfs_parent[v] = u;
      if (u == dfsRoot) rootChildren++;

      articulationPointAndBridge(v);

      if (dfs_low[v] >= dfs_num[u])
          articulation_vertex[u] = true;
      dfs_low[u] = min(dfs_low[u], dfs_low[v]);
    }
    else if (v != dfs_parent[u])
        dfs_low[u] = min(dfs_low[u], dfs_num[v]);
  }
}


int main(){
  while(scanf("%d",&V),V){
        getchar();
        char input[10010];
        AdjList.assign(V,vi());
        while(gets(input) && strcmp(input,"0")){
            char *pch;
            pch=strtok(input," ");
            int tmp1=atoi(pch);
            tmp1--;
            for(pch=strtok(NULL," ");pch;pch=strtok(NULL," ")){
                int tmp2=atoi(pch); tmp2--;
                AdjList[tmp1].push_back(tmp2);
                AdjList[tmp2].push_back(tmp1);
            }
        }
       dfsNumberCounter = 0; dfs_num.assign(V, DFS_WHITE); dfs_low.assign(V, 0);
       dfs_parent.assign(V, -1); articulation_vertex.assign(V, 0);

      for (int i = 0; i < V; i++)
        if (dfs_num[i] == DFS_WHITE) {
            dfsRoot = i; rootChildren = 0;
            articulationPointAndBridge(i);
       articulation_vertex[dfsRoot] = (rootChildren > 1);
    }
    int counter=0;
    for (int i = 0; i < V; i++)
    if (articulation_vertex[i]) counter++;
    printf("%d\n",counter);
  }
  return 0;
}
