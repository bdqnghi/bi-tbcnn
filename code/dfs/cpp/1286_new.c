#include "cstdio"

const int MAXN = 101;
int m, n;
char grid[MAXN][MAXN];

bool valid(int x, int y) {
    return x>=0 && x<m && y>=0 && y<n;
}

void dfs(int x, int y) {
    if (!valid(x, y) || grid[x][y] != '@') return;
    grid[x][y] = '.';
    dfs(x+1, y);
    dfs(x-1, y);
    dfs(x, y+1);
    dfs(x, y-1);
    dfs(x-1, y-1);
    dfs(x-1, y+1);
    dfs(x+1, y-1);
    dfs(x+1, y+1);
}

int gao() {
    int ret = 0;
    for (int i=0; i<m; i++) {
        for (int j=0; j<n; j++) {
            if (grid[i][j] == '@') {
                ret++;
                dfs(i, j);
            }
        }
    }
    return ret;
}

int main(int argc, char const *argv[])
{
    while (scanf("%d%d", &m, &n), m) {
        gets(grid[0]);
        for (int i=0; i<m; i++) {
            gets(grid[i]);
        }

        printf("%d\n", gao());
    }
    return 0;
}