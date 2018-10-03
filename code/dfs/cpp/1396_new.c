//UVA 572
// depth first search, dfs
#include<cstdio>
#include<cstring>
#define MAXN 105


char map[MAXN][MAXN];
char v[MAXN][MAXN];

void dfs(int i,int j, int m, int n) {
	if(i<0 || i>=m || j<0 || j>=n || v[i][j])
		return;
	v[i][j] = 1;
	if(map[i][j]=='@') {
		dfs(i-1,j-1,m,n);
		dfs(i-1,j,m,n);
		dfs(i-1,j+1,m,n);
		dfs(i,j-1,m,n);
		dfs(i,j+1,m,n);
		dfs(i+1,j-1,m,n);
		dfs(i+1,j,m,n);
		dfs(i+1,j+1,m,n);
	} else {
		return ;
	}
}

int main() {
	int m,n,pocket;
	
	while(scanf("%d %d",&m,&n),m&&n){
		getchar();
		for(int i=0;i<m;getchar(),i++) {
			for(int j=0;j<n;j++) {
				scanf("%c",&map[i][j]);
			}
		}
		memset(v,0,sizeof(v));
		pocket=0;
		for(int i=0;i<m;i++)
			for(int j=0;j<n;j++) {
				if(!v[i][j] && map[i][j]=='@') {
					dfs(i,j,m,n);
					pocket++;
				}
			}
		printf("%d\n",pocket);
	}	
	return 0;
}