/****
 * 572 - Oil Deposits
 */
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int m, n;
char map[101][101];

void dfs(int x, int y)
{
    if (map[x][y] == '*' || x < 0 || x == m || y < 0 || y == n)
        return;

    map[x][y] = '*';
    dfs(x-1, y-1);
    dfs(x-1, y);
    dfs(x-1, y+1);
    dfs(x, y-1);
    dfs(x, y+1);
    dfs(x+1, y-1);
    dfs(x+1, y);
    dfs(x+1, y+1);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    for (;;)
    {
        scanf("%d %d\n", &m, &n);
        if (m == 0) break;

        for (int i = 0; i < m; i++)
            gets(map[i]);

        int count = 0;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (map[i][j] == '@')
                {
                    dfs(i, j);
                    count ++;
                }
        printf("%d\n", count);
    }
    return 0;
}
