/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
using namespace std;
#define loop(i,start,end) for (lli i=start;i<=end;i++)
#define pool(i,start,end) for(lli i=start;i>=end;i--)
#define zyloc() lli t;cin>>t;while(t--)
#define vi(v) vector <long long  int> v;
#define pb(n) push_back(n)
#define mp(a,b) make_pair(a,b)
#define fill(a,value) memset(a,value,sizeof(a)) 
#define MOD 1000000007
#define PI  3.14159265358979323846
#define MAX 1000002
#define vpi(v) vector <pair <long long int, long long int> > v
#define lli long long int 
#define debug() cout<<"######"<<endl 
int main(){
	while(1){	
		lli maxSize,n,x,y;
		cin>>maxSize>>n;
		if (maxSize==0 and n==0){
			return 0;
		}
		vector<pair<lli,lli> >v;
		loop(i,0,n-1){
			cin>>x>>y;
			v.pb(mp(x,y));
		}
		lli dp[n+1][maxSize+1];
		memset(dp,0,sizeof(dp));
		loop(i,0,n-1){
			loop(j,1,maxSize){
				if (i==0){
					if (j>=v[i].first){
						dp[i][j] = v[i].second;
					}
					else{
						dp[i][j] = 0;
					}
				}
				else{
					if (j>=v[i].first){
						dp[i][j] = max(v[i].second+dp[i-1][j-v[i].first],dp[i-1][j]);
					}
					else{
						dp[i][j] = dp[i-1][j];
					}
				}
			}
		}
		lli maxFun(dp[n-1][maxSize]);
		lli row(n-1),col(maxSize);
		while(row!=0 and dp[row][col]==maxFun){
			row--;
		}
		cout<<row+1<<" "<<maxFun<<endl;
	}	
	return 0;
}	


/*     0 1 2 3 4
1 8  0 8 8 8 8 
2 4  0 8 8 12 12
3 0  
2 5
2 3*/

