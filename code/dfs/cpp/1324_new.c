// =========== Bridges and Articulations Points =========
// Complexity:
// Implementation time:
// Dependency:
// Description:

int adj[MAXN][MAXN];
int nadj[MAXN];

int dfs_low[MAXN], dfs_num[MAXN], dfs_parent[MAXN], ap[MAXN];
int counter, root, rootChildren;

int dfsbap(int u){
	int v;
	dfs_low[u] = dfs[u] = counter++;
	for(int j=0; j<nadj[u]; j++){
		v = adj[u][j];
		if(!dfs_num[v]){
			dfs_parent[v] = u;
			if(u==root) rootChildren++;
			dfsbap(v);
			if(dfs_low[v]>=dfs_num[u])
				ap[u]=1;
			if(dfs_low[v]>dfs_num[u])
				printf("Edge (%d,%d) is a bridge\n",u,v);
			dfs_low[u] = min(dfs_low[u],dfs_low[v]);

		}else if(v!=dfs_parent[u]){
			dfs_low[u] = min(dfs_low[u],dfs_num[v]);
		}
	}
}
