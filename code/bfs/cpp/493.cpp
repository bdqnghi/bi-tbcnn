#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<queue>

using namespace std;

void bfs(unordered_map<int, unordered_set<int> > &edges, int i) {
    unordered_set<int> visited;
    queue<int> q;
    q.push(i);
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        visited.insert(cur);
        for (auto it=edges[cur].begin(); it!=edges[cur].end(); it++) {
            if (visited.find(*it) == visited.end()) {
                q.push(*it);
            }
        }
    }
}

int main() {
    unordered_map<int, unordered_set<int> > edges;

    edges[0].insert(1);
    edges[0].insert(2);
    edges[1].insert(3);
    edges[2].insert(4);

    bfs(edges, 0);

    return 0;    
}
