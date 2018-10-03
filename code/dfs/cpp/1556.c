/*
- T(E, V) = O(E)
- Besides using visited or not as the state of a vertex, we can also use { unvisited, processing, visited } as its state.
*/

#include <vector>
#include <utility>
#include <functional>
#include <iostream>
#include <stack>

using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef function<void(int)> func;

void dfs_recursive_internal(vvii& g, int u, vector<bool>& visited, func f) {
    f(u);
    visited[u] = true;
    for (auto& e : g[u]) {
        int v = e.first;
        if (!visited[v])
            dfs_recursive_internal(g, v, visited, f);
    }
}

void dfs_recursive(vvii& g, int u, func f) {
    vector<bool> visited(g.size(), false);
    dfs_recursive_internal(g, u, visited, f);
}

void dfs_iterative(vvii& g, int u, func f) {
    stack<int> stack;
    stack.push(u);
    vector<bool> visited(g.size(), false);
    
    while (!stack.empty()) {
        u = stack.top();
        stack.pop();
        if (!visited[u]) {
            f(u);
            visited[u] = true;
            for (auto& e: g[u]) {
                int v = e.first;
                if (!visited[v])
                    stack.push(v);
            }
        }
    }
}

int main() {

/*
          40          10
    (0)------->(1)------>(3)
      \       ^  ^        |
     10\   10/    \10     | 30
        v   /      \      |
        (2)------->(4)<---'
              10
*/

    vvii g(5);
    g[0] = { { 1, 40}, { 2, 10} };
    g[1] = { { 3, 10} };
    g[2] = { { 1, 10}, { 4, 10} };
    g[3] = { { 4, 30 } };
    g[4] = { { 1, 10} };
    
    func f = [](int u){ cout << u << endl; };
    
    cout << "dfs_recursive:" << endl;
    dfs_recursive(g, 0, f);
    
    cout << "dfs_iterative:" << endl;
    dfs_iterative(g, 0, f);
