//https://www.codechef.com/COOK39/problems/PPTEST

#include <iostream>
#include <algorithm>

using namespace std;

const int maxn=101;
const int maxw=101;

int w[maxn];
int v[maxn];

int kp[maxn][maxw];

int knapsack(int *w,int *v, int n, int mw){
	
	for(int wt=0;wt<=mw;wt++)
		kp[0][wt]=0;

	for (int i = 1; i <= n; ++i)
	{
		for(int wt=0;wt<=mw;wt++){

			if(w[i]<=wt){
				kp[i][wt]=max(kp[i-1][wt-w[i]]+v[i] , kp[i-1][wt]);
			}else{
				kp[i][wt]=kp[i-1][wt];
			}
		}
	}

	return kp[n][mw];
}

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		int mw;
		cin>>n>>mw;
		for (int i = 1; i <= n; ++i)
		{
			int a,b;
			cin>>a>>b>>w[i];
			v[i]=a*b;
		}
		cout<<knapsack(w,v,n,mw)<<"\n";
	}

}