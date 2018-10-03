#include <stdio.h>

int m;
int n;
char grid [100 + 5] [100 + 5];
int cnt;

void dfs (int r, int c)
{
    if ( r < 0 || r >= m || c < 0 || c >= n || grid [r] [c] == '*' )
        return;

    grid [r] [c] = '*';

    dfs (r - 1, c); // up
    dfs (r - 1, c + 1); // top-right
    dfs (r, c + 1); // right
    dfs (r + 1, c + 1); // bottom-right
    dfs (r + 1, c); // bottom
    dfs (r + 1, c - 1); // bottom-left
    dfs (r, c - 1); // left
    dfs (r - 1, c - 1); // top-left
}

int main ()
{
    while ( scanf ("%d %d", &m, &n) )
    {
        if ( m == 0 && n == 0 )
            break;

        cnt = 0;

        for ( int i = 0; i < m; i++ )
        {
            scanf ("%s", grid [i]);
        }

        for ( int i = 0; i < m; i++ )
        {
            for ( int j = 0; j < n; j++ )
            {
                if ( grid [i] [j] == '@' )
                {
                    cnt++;
                    dfs (i, j);
                }
            }
        }

        printf ("%d\n", cnt);
    }

    return 0;
}