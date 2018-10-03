#include <cstdio>
#include <cstring>

using namespace std;

struct edge {
	int to;
	edge *next;
} edg[100010], *vert[1002], *r_vert[1002];

int n, m, top, order[1002], id[1002];
bool visit[1002];

void add_edge(int u, int v) {
	edge *p = &edg[++top];
	p->to = v;
	p->next = vert[u], vert[u] = p;

	p = &edg[++top];
	p->to = u;
	p->next = r_vert[v], r_vert[v] = p;
}

void DFS(int s) {
	visit[s] = true;
	for (edge *p = vert[s]; p != NULL; p = p->next) {
		if (!visit[p->to]) {
			DFS(p->to);
		}
	}
	order[top++] = s;
}

void DFS_RG(int s) {
	visit[s] = true;
	id[s] = top;
	for (edge *p = r_vert[s]; p != NULL; p = p->next) {
		if (!visit[p->to]) {
			DFS_RG(p->to);
		}
	}
}

int main() {
	int nca;
	scanf("%d", &nca);
	while (nca--) {
		scanf("%d%d", &n, &m);

		top = -1;
		memset(vert, 0, sizeof(vert));
		memset(r_vert, 0, sizeof(r_vert));
		for (int i = 0; i < m; i++) {
			int u, v;
			scanf("%d%d", &u, &v);
			add_edge(u, v);
		}
		top = 1;
		memset(visit, false, sizeof(visit));
		for (int i = 1; i <= n; i++) {
			if (!visit[i]) {
				DFS(i);
			}
		}
		top = 0;
		memset(visit, 0, sizeof(visit));
		for (int i = n; i > 0; i--) {
			if (!visit[order[i]]) {
				DFS_RG(order[i]);
				++top;
			}
		}
		printf("%d\n", top);
		scanf("%d", &n);
	}
	return 0;
}
