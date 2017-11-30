using namespace std;
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string>
#include <cstring>
#include <climits>

#define INF                         (int)1e9
#define EPS                         1e-9

#define bitcount                    __builtin_popcount
#define gcd                         __gcd

#define s(n)                         scanf("%d",&n)
#define sc(n)                        scanf("%c",&n)
#define sl(n)                        scanf("%lld",&n)
#define sf(n)                        scanf("%lf",&n)
#define ss(n)                        scanf("%s",n)
#define scana(a,t)                   for(int i = 0; i < t; i++){cin >> a[i];}

#define FOR(i,a,b)                	 for(int i=a;i<b;i++)
#define FOREACH(v, c)                for( typeof( (c).begin()) v = (c).begin();  v != (c).end(); ++v)
#define REP(i,a)                     for (int i=0; i<a; i++)

#define all(a)                        a.begin(), a.end()
#define in(a,b)                       ( (b).find(a) != (b).end())
#define pb                            push_back
#define fill(a,v)                     memset(a, v, sizeof a)
#define sz(a)                         ((int)(a.size()))

#define maX(a,b)                      ( (a) > (b) ? (a) : (b))
#define miN(a,b)                      ( (a) < (b) ? (a) : (b))
#define PI                     		  acos(-1)
#define sqr(x)                 		  ((x) * (x))

#define p(n)                          printf("%d\n",n)
#define pl(n)                         printf("%lld\n",n)
#define pul(n)                        printf("%llu\n", n);
#define pf(n)                         printf("%f\n",n)
#define pc(n)                         printf("%c\n",n)
#define ps(n)                         printf("%s\n",n)

#define sort(x)                       sort(all(x))
#define gsort(x)                      sort(all(x), greater<typeof(*((x).begin()))>())
#define mp 							  make_pair

#define DEBUG(x)               		  { cerr << #x << " = " << x << endl; }
#define PR(a,n)                		  {cerr<<#a<<" = "; FOR(_,1,n) cerr << a[_] << ' '; cerr <<endl;}
#define PR0(a,n)               		  {cerr<<#a<<" = ";REP(_,n) cerr << a[_] << ' '; cerr << endl;}

#define numTest(t)                    int t; s(t); while(t--)

typedef int64_t LL;
typedef pair<int,int> PII;
typedef pair<LL,LL> PLL;

typedef vector<int> VI;
typedef vector<LL> VL;
typedef vector<PII> VII;
typedef vector<PLL> VLL;

typedef vector<VI> VVI;
typedef vector<VL> VVL;
typedef vector<VII> VVII;
typedef vector<VLL> VVLL;

typedef vector<string> VS;
typedef vector<VS> VVS;

int knapsack(VVI& A, VI& v, VI& w, int N, int W)
{
	if (N <= 0 || W <= 0)
	{
		return 0;
	}
	if (A[N][W] != -1)
	{
		return A[N][W];
	}
	else
	{
		A[N][W] = max(knapsack(A,v,w,N-1,W), (W-w[N] < 0) ? -1 :knapsack(A,v,w,N-1,W-w[N]) + v[N]);
		return A[N][W];
	}
}
int main()
{	
	#ifndef ONLINE_JUDGE
		freopen ("knapsack1.txt", "r", stdin);
		// freopen ("out.txt", "w", stdout);
	#endif
	int W, N; cin>>W>>N;
	VL v(N+1), w(N+1);
	LL w_min = LONG_MAX;
	FOR(i,1,N+1)
	{
		cin>>v[i]>>w[i];
		if (w[i] < w_min)
		{
			w_min = w[i];
		}
	}

	VVL A(2, VL(W+1));
	int p = 0, q = 1;
	for (int i = 1; i <= N; ++i)
	{
		for (int x = w_min; x <= W; ++x)
		{
			A[q][x] = max(A[p][x], (x - w[i] < 0) ? 0 : A[p][x - w[i]] + v[i]);
		}
		swap(p,q);
	}
	cout<<A[N%2][W];

	return 0;
}