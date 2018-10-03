#define VISITED 1
#define NOT_VISITED 0
int n, e; // number of nodes and edges
vector<vi> graph; // adjacency list of the graph
int dfsm[MAX]; // max number of vertices in the graph

void dfs(int start) {
	dfsm[start] = VISITED;
	DBG(start);
	for (int i = 0; i < graph[start].size(); i++) {
		if(dfsm[graph[start][i]] == NOT_VISITED) {
			dfs(graph[start][i]);
		}
	}
}

int main() {
	scanf("%d %d", &n, &e);
	graph = vector<vi>(n);
	int ns, nt;
	while(e--) {
		scanf("%d %d", &ns, &nt);
		graph[ns].push_back(nt);
	}
	memset(dfsm, NOT_VISITED, sizeof dfsm);
	dfs(0);
	return 0;
}
