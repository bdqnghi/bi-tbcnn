#include<iostream>
#include<cstring>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<sstream>
#include<cstdio>
#include<cctype>
#include <fstream>
#include<vector>
using namespace std;

vector <int> v;

int main()
{
    int m,s,i,j,n;
    cin>>m;
    n=m;
    s=0;
    int dp[100][501]={{0}};
    while(m--)
    {
              cin>>i;
              s+=i;
              v.push_back(i);
    }
    
    for(j=1;j<=s;j++)
    {cout<<endl;
    for(i=1;i<=n;i++)
    {if(v[i]>j)dp[i][j]=dp[i-1][j];
    else dp[i][j]= 1+max(dp[i-1][j],dp[i-1][j-v[i]]);
    cout<<dp[i][j]<<" ";
    }
}

system("pause");

}
    
    
    
    
    
    
    
    
    
    
