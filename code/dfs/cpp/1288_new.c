#include <iostream>

using namespace std;

int m, n;
char grid[26][26];

void dfs(int r, int c)
{
    if(r < 0 || r >= m || c < 0 || c >= n || grid[r][c] == '0')
        return;

    grid[r][c] = '0';
    dfs(r-1, c);    //left
    dfs(r+1, c);    //right
    dfs(r, c-1);    //top
    dfs(r, c+1);    //bot
    dfs(r-1, c-1);  //top-left
    dfs(r-1, c+1);  //bot-left
    dfs(r+1, c-1);  //top-right
    dfs(r+1, c+1);  //bot-right

}

int main()
{
    int count, caseNum = 1;
    while(cin >> m)
    {
        count = 0;
        n = m;

        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                cin >> grid[i][j];

        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                if(grid[i][j] == '1'){
                    count++;
                    dfs(i,j);
                }
        cout << "Image number " << caseNum++ << " contains " << count << " war eagles." << endl;
    }
    return 0;
}
