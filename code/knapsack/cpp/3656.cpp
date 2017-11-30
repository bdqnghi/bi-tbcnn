#include<bits/stdc++.h>
using namespace std;
int max(int a, int b) { return (a > b)? a : b; }
int main()
{
  long long int i,s,t,j;
  while(scanf("%lld",&s)!=EOF)
  { scanf("%lld",&t);
  long long int k[t+1],arr[t+1];
  for(i=0;i<t;i++)
     scanf("%lld %lld",&k[i],&arr[i]);  
  long long int dp[t+1][s+1];
  for(i=0;i<=t;i++)
     for(j=0;j<=s;j++){
         if(i==0 || j==0) dp[i][j]=0;
         else if(k[i-1]>j) dp[i][j]=dp[i-1][j];
         else dp[i][j]=max(dp[i-1][j],arr[i-1]+dp[i-1][j-k[i-1]]);
      }
  printf("%lld\n",dp[t][s]);
  }
  return 0;
}

