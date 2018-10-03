//graph fragments

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

vector<vii> neighbours;

void dfs(int u) {
  printf(" %d", u);
  dfs_num[u] = DFS_BLACK;
  vii n = neighbours[u];
  for (vii::iterator v = n.begin(); v != n.end(); n++) {
    if (dfs_num[v->first] == DFS_WHITE) {
      dfs(v->first);
    }
  } 
}

void articulationPoint(int u) {
  dfs_low[u] = dfs_num[u] = clock++;
  TRvii (AdjList[u], v)
    if (dfs_num[v->first] == DFS_WHITE) {
      dfs_parent[v->first] = u;
    if (u == dfsRoot)
      rootChildren++;
    articulationPoint(v->first);
    if (dfs_low[v->first] >= dfs_num[u])
      articulation_vertex[u] = true;
    dfs_low[u] = min(dfs_low[u], dfs_low[v->first]);
  }
  else if (v->first != dfs_parent[u])
    dfs_low[u] = min(dfs_low[u], dfs_num[v->first]);
}

void Bridge(int u) {
  dfs_low[u] = dfs_num[u] = clock++;
  TRvii (AdjList[u], v)
    if (dfs_num[v->first] == DFS_WHITE) {
      dfs_parent[v->first] = u;
    if (u == dfsRoot)
      rootChildren++;
    Bridge(v->first);
    if (dfs_low[v->first] > dfs_num[u])
      printf(" Edge (%d, %d) is a bridge\n", u, v->first);
    dfs_low[u] = min(dfs_low[u], dfs_low[v->first]);
  }
  else if (v->first != dfs_parent[u])
    dfs_low[u] = min(dfs_low[u], dfs_num[v->first]);
}