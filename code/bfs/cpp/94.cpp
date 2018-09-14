#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <math.h>
#include <cctype>
#include <set>
#include <string>
#include <queue>
#include <stack>
#include <list>

using namespace std;

vector<int> graph[1000];

void BFS(int startNode, int nodes){
    queue<int> q;
    bool visited[nodes];
    memset(visited, false, sizeof(visited));
    
    q.push(startNode);
    visited[startNode] = true;
    
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        
        cout << x << " > ";
        
        for (int i = 0; i < graph[x].size(); i++) {
            if(!visited[graph[x][i]]){
                visited[graph[x][i]] = true;
                q.push(graph[x][i]);
            }
        }
    }
    cout << endl;
}

int main(){
    int nodes, edges, u, v;
    cin >> nodes >> edges;
    
    for (int i = 0; i < edges; i++) {
        cin >> u >> v;
        graph[u].push_back(v);
    }
    
    BFS(2, nodes);
    return 0;
}
