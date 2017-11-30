#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int v[n],w[n];
    for(int i=0;i<n;i++)
    {
        cin>>v[i]>>w[i];
    }
    int W;
    cin>>W;
    int X[n+1][W+1];
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=W;j++)
        {
            if(i==0||j==0)
            {
                X[i][j]=0;
            }
            else if(w[i-1]<=W)
            {
                X[i][j]=max(v[i-1]+X[i-1][j-w[i-1]],X[i-1][j]);
            }
            else
            {
                X[i][j]=X[i][j-1];
            }
        }
    }
    cout<<X[n][W];
    return 0;
}
