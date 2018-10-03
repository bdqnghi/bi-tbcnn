vi dfs_num, dfs_low, S,visited;
int dfsNumberCounter, numSCC;

void tarjanSCC(int u) {
	dfs_low[u] = dfs_num[u] = dfsNumberCounter++;
	S.push_back(u);
	visited[u] = 1;
	for (int j = 0; j < g[u].size(); j++) {
		int v = g[u][j];
		if (dfs_num[v] == DFS_WHITE) tarjanSCC(v);
		if (visited[v]) dfs_low[u] = min(dfs_low[u], dfs_low[v]);
	}
	if (dfs_low[u] == dfs_num[u]) {
		cout << "SCC " << ++numSCC << ":";
		while (1) {
			int v = S.back();
			S.pop_back();
			visited[v] = 0;
			cout << " " << v;
			if (u == v) break;
		}
		cout << endl;
	}
}

int main() {
	/* Build graph */
	dfs_num.assign(n, DFS_WHITE);
	dfs_low.assign(n,0);
	visited.assign(n, 0);
	dfsNumberCounter = numSCC = 0;
	for (int i = 0; i < n; i++)
		if (dfs_num[i] == DFS_WHITE)
			tarjanSCC(i);
	return 0;
}
