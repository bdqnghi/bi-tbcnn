#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <set>
#include <stack>
#include <map>

#define DFS_WHITE   -1
#define DFS_BLACK   1
#define DFS_GRAY    2

using namespace std;

typedef pair<int,int>   ii;
typedef vector<ii>      vii;


int V;
int dfsNumberCounter=1, dfsRoot, rootChildren;
vector<int> dfs_num, dfs_low,dfs_parent;
vector<bool> articulation_vertex;

vector<vii> AdjList;

void articulationPointAndBridge(int u){
    dfs_low[u] = dfs_num[u] = dfsNumberCounter++;
    for(int j=0; j< (int) AdjList[u].size();j++){
        ii v = AdjList[u][j];
        if(dfs_num[v.first] == DFS_WHITE){
            dfs_parent[v.first] = u;
            if(u == dfsRoot) rootChildren++;

            articulationPointAndBridge(v.first);

            if(dfs_low[v.first] >= dfs_num[u]){
                articulation_vertex[u] = true;
                //printf("current: %d, next vertex: %d, dfs_low of current: %d, dfs_num of next: %d\n",u,v.first,dfs_low[u],dfs_num[v.first]);
            }
            dfs_low[u] = min(dfs_low[u],dfs_low[v.first]);
        } else if(v.first != dfs_parent[u]) dfs_low[u] = min(dfs_low[u],dfs_num[v.first]);
    }
}

bool mm[105][105];

int main(){

    while(scanf("%d",&V),V){
        dfsNumberCounter = 0; dfs_num.assign(V,DFS_WHITE); dfs_low.assign(V,0);
        dfs_parent.assign(V,0); articulation_vertex.assign(V,0);
        AdjList.clear();
        memset(mm,0,sizeof mm);
        for(int i=0;i<V;i++)    AdjList.push_back(vector<ii>());
        
        string buf;
        getline(cin,buf);
        while(getline(cin,buf) && buf[0] != '0'){
            //cout << "buf: " << buf << ", ccc = " << ccc << endl;
            istringstream in(buf);
            int u,t; in >> u;
            while(in >> t){
                mm[u-1][t-1] = mm[t-1][u-1] = true;
            }
        }
        
        for(int i=0;i<V;i++)    for(int j=0;j<V;j++)    if(mm[i][j])    AdjList[i].push_back(make_pair(j,0));

        // print edge list
        /*
        printf("Edge List: \n");
        for(int i=0;i<V;i++){
            printf("%d: ",i+1);
            for(int j=0;j<AdjList[i].size();j++)    printf("%d ",AdjList[i][j].first+1);
            putchar('\n');
        }
        */

        for(int i=0;i<V;i++){
            if( dfs_num[i] == DFS_WHITE){
                dfsRoot = i; rootChildren = 0;
                articulationPointAndBridge(i);
                articulation_vertex[dfsRoot] = (rootChildren > 1);
                // cout << i+1 << ": root children number: " << rootChildren << endl;
            }
        }
        // output the vertex #
        /*
        printf("DFS Low: ");
        for(int i=0;i<V;i++){
            printf("%d:%d ",i+1,dfs_low[i]);
        }
        putchar('\n');
        printf("DFS Num: ");
        for(int i=0;i<V;i++){
            printf("%d:%d ",i+1,dfs_num[i]);
        }
        putchar('\n');
        */


        int count = 0;
        for(int i=0;i<V;i++){
            if(articulation_vertex[i]){
                count++;
         //       printf("vertex: %d\n", i+1);
            }
        }
        printf("%d\n",count);
    }

    return 0;
}
