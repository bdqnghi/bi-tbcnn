#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long LL;
const int maxn=50;
int n,h;
LL dp[maxn][maxn];
int vis[maxn][maxn];
LL dfs(int c,int d)
{
	if(c<d) return 0;
	if(c==0) return d==0?1:0;
	if(d==0) return dfs(c,1);
	if(vis[c][d]) return dp[c][d];
	vis[c][d]=1;
	LL &ans=dp[c][d];
	ans=dfs(c,d+1);
	for(int i=1;i<=c;i++)
	{
		ans+=(dfs(i-1,d-1)-dfs(i-1,d))*(dfs(c-i,0)-dfs(c-i,d-1));
		ans+=(dfs(i-1,0)-dfs(i-1,d-1))*(dfs(c-i,d-1)-dfs(c-i,d));
		ans+=(dfs(i-1,d-1)-dfs(i-1,d))*(dfs(c-i,d-1)-dfs(c-i,d));
	}
	return ans;
}
int main()
{
	scanf("%d%d",&n,&h);
	memset(vis,0,sizeof(vis));
	LL ans=dfs(n,h);
	cout<<ans<<"\n";
	return 0;
}
