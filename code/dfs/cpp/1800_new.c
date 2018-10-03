#include <string.h>
#include <iostream>
using namespace std;

int logg[52];
int dfs[51][51];

int main() {
	int l, n, i, j, k;
	memset(logg, 0, sizeof(logg));
	memset(dfs, 0, sizeof(dfs));
	while (cin >> l, l) {
		for (cin >> n, i = 1; i <= n; i++) cin >> logg[i];
		logg[n + 1] = l;
		for (i = 2; i <= n + 1; i++) {
			for (j = 0; j <= n + 1 - i; j++) {
				for (k = 1; k < i; k++) {
					if (k == 1) dfs[j][j + i] = logg[j + i] - logg[j] + dfs[j][j + k] + dfs[j + k][j + i];
					else dfs[j][j + i] = min(dfs[j][j + i], logg[j + i] - logg[j] + dfs[j][j + k] + dfs[j + k][j + i]);
				}
			}
		}
		cout << "The minimum cutting is " << dfs[0][n + 1] << ".\n";
	}
}