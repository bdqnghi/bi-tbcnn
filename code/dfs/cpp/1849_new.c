#include<iostream>
using namespace std;
int ch[101][101],n,m,ans;
int dfs(int i,int j,int dir,int k)
{
    if(ch[i][j] || i>=n || i<0 || j<0 || j>=m) return 0;
    ch[i][j]=k;
    if(dir==0)
    {
           if(dfs(i,j+1,1,k+1))return 1;
          if(dfs(i+1,j,2,k+1))return 1;
          if(dfs(i,j-1,3,k+1))return 1;
          if(dfs(i-1,j,4,k+1))return 1;
    }
    if(dir==4)
    {
          if(dfs(i,j+1,1,k+1))return 1;
          if(dfs(i+1,j,2,k+1))return 1;
          if(dfs(i,j-1,3,k+1))return 1;
          if(dfs(i-1,j,4,k+1))return 1;
    }
    if(dir==1)
    {
          if(dfs(i+1,j,2,k+1))return 1;
          if(dfs(i,j-1,3,k+1))return 1;
          if(dfs(i-1,j,4,k+1))return 1;
          if(dfs(i,j+1,1,k+1))return 1;
    }
    if(dir==2)
    {
          if(dfs(i,j-1,3,k+1))return 1;
          if(dfs(i-1,j,4,k+1))return 1;
          if(dfs(i,j+1,1,k+1))return 1;
          if(dfs(i+1,j,2,k+1))return 1;
    }
    if(dir==3)
    {
          if(dfs(i-1,j,4,k+1))return 1;
          if(dfs(i,j+1,1,k+1))return 1;
          if(dfs(i+1,j,2,k+1))return 1;
          if(dfs(i,j-1,3,k+1))return 1;
    }
    return 1;
}
int main()
{
    cin>>n>>m;
    dfs(0,0,0,1);
    for(int i=0;i<n;i++)
    {
                    for(int j=0;j<m;j++)
                    {
                                    ans=max(ans,ch[i][j]);
                    }
    }
    cout<<ans<<endl;
    cin>>n>>m;
}
