#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e4;
const int MAXM = 5e4;
int n, m, dfs_num[MAXN+5], dfs_low[MAXN+5], dfs_parent[MAXN+5];
int counter, bridgeCnt;
bool arti[MAXN+5];
vector<int> adj[MAXN+5];

int dfs(int u) {
    dfs_num[u] = dfs_low[u] = ++counter;
    int childCnt = 0;
    for (int i = 0; i < (int)adj[u].size(); ++i) {
        int v = adj[u][i];
        if (!dfs_num[v]) {
            dfs_parent[v] = u;
            ++childCnt;
            dfs(v);
            if (dfs_low[v] >= dfs_num[u])
                arti[u] = true;
            if (dfs_low[v] > dfs_num[u])
                ++bridgeCnt;
            dfs_low[u] = min(dfs_low[u], dfs_low[v]);
        } else if (v != dfs_parent[u]) {
            dfs_low[u] = min(dfs_low[u], dfs_num[v]);
        }
    }
    return childCnt;
}

int main() {
    scanf("%d %d", &n, &m);

    for (int i = 0, u, v; i < m; ++i) {
        scanf("%d %d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 1; i <= n; ++i)
    if (!dfs_num[i]) {
        arti[i] = (dfs(i) > 1);
    }

    int artiCnt = 0;
    for (int i = 1; i <= n; ++i)
        artiCnt += arti[i];
    printf("%d %d\n", artiCnt, bridgeCnt);
    return 0;
}
