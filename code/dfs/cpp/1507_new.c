#include <stdio.h>
#include <string.h>

using namespace std;

char data[102][102];
bool used[102][102];
int n,m;

void dfs(int a, int b)
{
    if (a < 0 || b < 0 || a >= n || b >= m || used[a][b] || data[a][b] == '.')
        return;
    used[a][b] = true;
    dfs(a + 1, b);
    dfs(a - 1, b);
    dfs(a, b + 1);
    dfs(a, b - 1);
    dfs(a + 1, b + 1);
    dfs(a + 1, b - 1);
    dfs(a - 1, b + 1);
    dfs(a - 1, b - 1);
}

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        scanf("%s", data[i]);
    }
    memset(used, 0, sizeof(used));
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        if (!used[i][j] && data[i][j] == 'W')
        {
            count ++;
            dfs(i, j);
        }
    }
    printf("%d\n", count);
    return 0;
}
