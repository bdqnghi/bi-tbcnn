#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <ctime>
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define REP(i,a,b) for(int i=int(a);i<int(b);i++)
#define sz size()
#define fill(x,i) memset(x,i,sizeof(x))
#define foreach(c,it) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
#define INF 1<<30
using namespace std;
int dp[2][2005],C,N;
int W[2000],V[2002];
void solve(){
	scanf("%d %d",&C,&N);
	REP(i,0,N)scanf("%d %d",&W[i],&V[i]);
	fill(dp,0);
	for(int i=1;i<=N;i++){
		int ii=i&1;
		for(int c=0;c<=C;c++){
			dp[ii][c]=dp[1-ii][c];
			if(c>=W[i-1])
				dp[ii][c]=max(dp[ii][c],dp[1-ii][c-W[i-1]]+V[i-1]);
			
		}
	}
	int ans=0;
	for(int c=0;c<=C;c++)ans=max(ans,dp[N&1][c]);
	
	printf("%d\n",ans);
}
int main(){
	#ifdef LocalHost
		freopen("E:/input.txt","r",stdin);
		clock_t start = clock();
	#endif
	solve();	
	#ifdef LocalHost
		fprintf(stderr, "\ntime=%.3lfsec\n", 0.001 * (clock() - start));
	#endif
	return 0;
}

