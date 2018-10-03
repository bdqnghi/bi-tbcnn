/*
 * Graph DFS Applications.
 *
 * Reference : http://www.comp.nus.edu.sg/~stevenha/myteaching/competitive_programming/ch4.zip
 */

#include <cstdio>
#include <algorithm>
#include <vector>
#include <cassert>

using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

#define DFS_WHITE -1
#define DFS_BLACK 1

vector<vii> AdjList;

vi dfs_num;
vi topoSort;
int V;

void dfs_toposort(int u) {
    dfs_num[u] = DFS_BLACK;
    for (int j = 0; j < (int)AdjList[u].size(); j++) {
        ii v = AdjList[u][j];
        if (dfs_num[v.first] == DFS_WHITE)
            dfs_toposort(v.first);
    }
    topoSort.push_back(u);
}

void test_topological_sort() {
    int ans1[] = {0, 1, 2, 3, 4};
    int ans2[] = {6, 8, 7};

    dfs_num.assign(V, DFS_WHITE);
    dfs_toposort(0); 
    assert(equal(topoSort.rbegin(), topoSort.rend(), ans1));
    topoSort.clear();
    dfs_toposort(6); 
    assert(equal(topoSort.rbegin(), topoSort.rend(), ans2));
}

#define DFS_GRAY 2
vi dfs_parent;
vii back_edge;

void graph_check(int u) {
    dfs_num[u] = DFS_GRAY;
    for (int j = 0; j < AdjList[u].size(); j++) {
        ii v = AdjList[u][j];
        if (dfs_num[v.first] == DFS_WHITE) {
            dfs_parent[v.first] = u;
            graph_check(v.first);
        } else if (dfs_num[v.first] == DFS_GRAY) {
            if (v.first != dfs_parent[u])
                back_edge.push_back(ii(u, v.first));
        } else if (dfs_num[v.first] == DFS_BLACK) {
            // cross edge or forward edge
        }
    }
    dfs_num[u] = DFS_BLACK;
}

void test_dfs_tree_check() {
    ii back_edge_arr[] = {ii(3, 1)};
    dfs_parent.assign(V, -1);
    dfs_num.assign(V, DFS_WHITE);
    graph_check(0);

    assert(equal(back_edge.begin(), back_edge.end(), back_edge_arr));
}

vi dfs_low;
vi articulation_vertex;
int dfs_number_counter, dfs_root, root_children;
vii bridge;

void find_articulation_point(int u) {
    dfs_low[u] = dfs_num[u] = dfs_number_counter++;
    for (int j = 0; j < AdjList[u].size(); j++) {
        ii v = AdjList[u][j];
        if (dfs_num[v.first] == DFS_WHITE) {
            dfs_parent[v.first] = u;
            if (u == dfs_root)
                root_children++;
            find_articulation_point(v.first);
            if (dfs_low[v.first] >= dfs_num[u])
                articulation_vertex[u] = true;
            if (dfs_low[v.first] > dfs_num[u])
                bridge.push_back(ii(u, v.first));
            dfs_low[u] = min(dfs_low[u], dfs_low[v.first]);
        } else if (v.first != dfs_parent[u]) {
            dfs_low[u] = min(dfs_low[u], dfs_num[v.first]);
        }
    }
}

void test_articulation_points_and_bridges() {
    int articulation_vertex_arr[] = {0, 1, 0, 1, 0, 0, 1, 0, 0};
    ii bridge_arr[] = {ii(0, 1), ii(3, 4), ii(6, 7), ii(6, 8)};

    dfs_number_counter = 0;
    dfs_num.assign(V, DFS_WHITE);
    dfs_low.assign(V, 0);
    dfs_parent.assign(V, -1);
    articulation_vertex.assign(V, 0);

    for (int i = 0; i < V; i++) {
        dfs_root = i; root_children = 0;
        if (dfs_num[i] == DFS_WHITE) {
            find_articulation_point(i);
            articulation_vertex[dfs_root] = (root_children > 1);
        }
    }

    assert(equal(articulation_vertex.begin(), articulation_vertex.end(),
                articulation_vertex_arr));

    sort(bridge.begin(), bridge.end());
    assert(equal(bridge.begin(), bridge.end(), bridge_arr));
} 

vi S, visited;
int num_scc;
vector<vi> scc;

void tarjan_scc(int u) {
    dfs_low[u] = dfs_num[u] = dfs_number_counter++;
    S.push_back(u);
    visited[u] = 1;
    for (int j = 0; j < (int)AdjList[u].size(); j++) {
        ii v = AdjList[u][j];
        if (dfs_num[v.first] == DFS_WHITE)
            tarjan_scc(v.first);
        if (visited[v.first])
            dfs_low[u] = min(dfs_low[u], dfs_low[v.first]);
    }

    if (dfs_low[u] == dfs_num[u]) {
        while (1) {
            int v = S.back(); S.pop_back(); visited[v] = 0;
            if (u == v)
                break;
        }
        ++num_scc;
    }

}

void test_scc() {
    dfs_num.assign(V, DFS_WHITE);
    dfs_low.assign(V, 0);
    visited.assign(V, 0);
    dfs_number_counter = num_scc = 0;

    for (int i = 0; i < V; i++)
        if (dfs_num[i] == DFS_WHITE)
            tarjan_scc(i);
    
    assert(num_scc == 3);
}

#define addEdge(from, to, weight) AdjList[(from)].push_back(ii((to), (weight)))

void inputUndirected() {
    V = 9;
    AdjList.assign(V, vii());

    addEdge(0, 1, 0);
    addEdge(1, 0, 0); addEdge(1, 2, 0); addEdge(1, 3, 0); 
    addEdge(2, 1, 0); addEdge(2, 3, 0);
    addEdge(3, 1, 0); addEdge(3, 2, 0); addEdge(3, 4, 0);
    addEdge(4, 3, 0);
    addEdge(6, 7, 0); addEdge(6, 8, 0);
    addEdge(7, 6, 0);
    addEdge(8, 6, 0); 
}

void inputDirected() {
    V = 8;
    AdjList.assign(V, vii());

    addEdge(0, 1, 0);
    addEdge(1, 3, 0); 
    addEdge(2, 1, 0);
    addEdge(3, 2, 0);
    addEdge(4, 5, 0);
    addEdge(5, 7, 0);
    addEdge(6, 4, 0);
    addEdge(7, 6, 0);
}


int main() {
    inputUndirected();

    // Topological Sort
    test_topological_sort();
    
    // DFS Spanning Tree Edge Check
    test_dfs_tree_check();
    
    // Articulation Points & Bridges
    test_articulation_points_and_bridges();
    
    inputDirected();

    // Strongly Connected Components
    test_scc();

    return 0;
}
