//01 knapsack

#include<cstdio>
#include<iostream>
using namespace std;
int max(int a,int b)
{
    if(a>b) return a;
    return b;
}
int main()
{
    int n,W;
    scanf("%d %d",&n,&W);
    int wt[n],v[n];
    for(int i=0;i<n;i++) scanf("%d",&v[i]);
    for(int i=0;i<n;i++) scanf("%d",&wt[i]);
    int ans[W+1][n+1];


    /*for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=W;j++)
        {
            if(i==0 || j==0)
                ans[i][j]=0;
            else if(j>=wt[i-1])
                ans[i][j]=max(ans[i-1][j], ans[i-1][j-wt[i-1]]+v[i-1] );
            else
                ans[i][j]=ans[i-1][j];
        }
    }*/
    for(int i=0;i<=W;i++)
    {
        for(int j=0;j<=n;j++)
        {
            if(i==0||j==0)
                ans[i][j]=0;
            else if(i>=wt[j-1])
            {
                ans[i][j]=max(ans[i][j-1], ans[i-wt[j-1]][j-1]+v[j-1]);
            }
            else    ans[i][j]=ans[i][j-1];
        }
    }

    printf("%d",ans[W][n]);
}
