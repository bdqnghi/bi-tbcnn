#include <iostream>

using namespace std;

int r,c,x,y,i,j;
char g[22][22];
char visited[22][22];
int res;

void dfs(int x,int y)
{
	if(visited[x][y]==1)
		return;
	visited[x][y]=1;
	if(x==1||g[x-1][y]=='.')
		res++;
	else
		dfs(x-1,y);
	if(x==r||g[x+1][y]=='.')
		res++;
	else
		dfs(x+1,y);
	if(y==1||g[x][y-1]=='.')
		res++;
	else
		dfs(x,y-1);
	if(y==c||g[x][y+1]=='.')
		res++;
	else
		dfs(x,y+1);
	if(x!=1 && y!=1 && g[x-1][y-1]=='X')
		dfs(x-1,y-1);
	if(x!=r && y!=c && g[x+1][y+1]=='X')
		dfs(x+1,y+1);
	if(x!=1 && y!=c && g[x-1][y+1]=='X')
		dfs(x-1,y+1);
	if(x!=r && y!=1 && g[x+1][y-1]=='X')
		dfs(x+1,y-1);
}

int main()
{
	while(cin >> r >> c >> x >> y){
		if(r==0 && c==0 && x==0 && y==0)
			break;
		for(i=1;i<=r;i++){
			for(j=1;j<=c;j++){
				cin >> g[i][j];
			}
		}
		memset(visited,0,sizeof(char)*22*22);
		res = 0;
		dfs(x,y);
		cout << res << endl;
	}
	return 0;
}