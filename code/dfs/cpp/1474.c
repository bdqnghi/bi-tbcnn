#include <fstream>
#include <vector>

using namespace std;

void dfs(const int& v,const vector< vector<int> >& graph, vector<bool>& visited) {
	visited[v] = true;
	for (const int& w : graph[v]) {
		if (!visited[w]) {
			dfs(w, graph, visited);
		}
	}
}

int main() {
	ifstream cin("dfs.in");
	ofstream cout("dfs.out");
	int n, m;
	cin >> n >> m;
	vector< vector< int > > graph(n);
	vector<bool> visited(n);
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		x--, y--;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}
	
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (!visited[i]) {
			ans++;
			dfs(i, graph, visited);
		}
	}
	cout << ans;
	return 0;
}