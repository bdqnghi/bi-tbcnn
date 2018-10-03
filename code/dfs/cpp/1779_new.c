#include<stdio.h>
int arr[1009][1009];
void dfs(int i,int j,int n)
 {
   if(i<0||i>=n||j<0||j>=n||arr[i][j]==0)
     return;
   arr[i][j]=0;
   dfs(i-1,j-1,n);
   dfs(i-1,j,n);
   dfs(i-1,j+1,n);
   dfs(i,j-1,n);
   dfs(i,j+1,n);
   dfs(i+1,j-1,n);
   dfs(i+1,j,n);
   dfs(i+1,j+1,n);
   return;
}     
int main()
 {
   int t,n,count,i,j;
   scanf("%d",&t);
   while(t--)
    {
     scanf("%d",&n);
     count=0;
     for(i=0;i<n;i++)
       for(j=0;j<n;j++)
         scanf("%d",&arr[i][j]);
     for(i=0;i<n;i++)
       for(j=0;j<n;j++)
         {
          if(arr[i][j]==1)
            {
             count++;
             dfs(i,j,n);
            }
         }             
     printf("%d\n",count);
    }
   return 0;
 }            
