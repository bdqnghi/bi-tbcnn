// FOR DFS 2386
#include<stdio.h>
char s[102][102];
int a[102][102],n,m;
void dfs(int x,int y)
{
	a[x][y]=1;
	if(x-1>=0&&y-1>=0&&s[x-1][y-1]=='@'&&!a[x-1][y-1]) dfs(x-1,y-1);//左上
	if(x-1>=0&&s[x-1][y]=='@'&&!a[x-1][y]) dfs(x-1,y);//上
	if(x-1>=0&&y+1<m&&s[x-1][y+1]=='@'&&!a[x-1][y+1]) dfs(x-1,y+1);//右上
	if(x+1<n&&s[x+1][y]=='@'&&!a[x+1][y]) dfs(x+1,y);//下
	if(y+1<m&&s[x][y+1]=='@'&&!a[x][y+1]) dfs(x,y+1);//右
	if(y-1>=0&&s[x][y-1]=='@'&&!a[x][y-1]) dfs(x,y-1);//左
	if(x+1<n&&y-1>=0&&s[x+1][y-1]=='@'&&!a[x+1][y-1]) dfs(x+1,y-1);//左下
	if(x+1<n&&y+1<m&&s[x+1][y+1]=='@'&&!a[x+1][y+1]) dfs(x+1,y+1);//右下
}
int main()
{
	int i,j,sum;
	while(scanf("%d%d",&n,&m)&&n&&m)
	{
		sum=0;
		for(i=0;i<n;i++)scanf("%s",s[i]);
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)a[i][j]=0;
		}
		for(i=0;i<n;i++)
		{
			for(j=0;s[i][j];j++)
			{
				if(s[i][j]=='@'&&a[i][j]==0)
				{
					sum++;
					dfs(i,j);
				}
			}
		}
		printf("%d\n",sum);

	}
	return 0;
}
