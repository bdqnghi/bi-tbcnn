#include <iostream>

using namespace std;

int m, n;
char grid[101][101];

int dfs(int r, int c)
{
    if(r < 0 || r >= m || c < 0 || c >= n || grid[r][c] == '.')
        return 0;

    int ans = 1;
    grid[r][c] = '.';

    ans += dfs(r-1, c);    //left
    ans += dfs(r+1, c);    //right
    ans += dfs(r, c-1);    //top
    ans += dfs(r, c+1);    //bot
    ans += dfs(r-1, c-1);  //top-left
    ans += dfs(r-1, c+1);  //bot-left
    ans += dfs(r+1, c-1);  //top-right
    ans += dfs(r+1, c+1);  //bot-right

    return ans;
}

int main()
{
    int count;
    while(cin >> m >> n)
    {
        count = 0;
        if(m == 0)  break;

        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                cin >> grid[i][j];

        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                if(grid[i][j] == '*' && dfs(i,j) == 1)
                    count++;

        cout << count << endl;
    }
    return 0;
}
