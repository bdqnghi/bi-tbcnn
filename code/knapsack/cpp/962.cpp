#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<limits>
#include<stdlib.h>
using namespace std;

#define N 3
#define W 50

typedef struct item{
  item():value(0), weight(0) {}
  int value;
  int weight;
} Item;

int knapsack1(int n, int w, int dp[][W+1], const Item *data){
  if(n==0||w==0) return 0;
  if(w<0) return numeric_limits<int>::min();

  if(dp[n][w]>0) return dp[n][w];

  int weight = data[n-1].weight;
  int value = data[n-1].value;
  dp[n][w] = max( knapsack1(n-1,w,dp,data), (knapsack1(n-1,w-weight,dp, data)+value) );
  return dp[n][w];
}

int knapsack2(int n, int w, int *dp, const Item *data){
  for(int i=0;i<N;++i){
    int weight = data[i].weight;
    int value = data[i].value;
    for(int j=w;j-weight>=0;--j){
      dp[j] = max(dp[j], dp[j-weight]+value);
    }
  }
  return dp[w];
}

int knapsack2U(int n, int w, int *dp, const Item *data){
  int last[W+1] = {0};
  for(int i=0;i<N;++i){
    int weight = data[i].weight;
    int value = data[i].value;
    for(int j=weight;j<=w;++j){
      if(dp[j-weight] + value > dp[j]) last[j] = i;
      dp[j] = max(dp[j], dp[j-weight]+value);
    }
  }

  int m = w;
  printf("put: ");
  while(m>=0){
    printf("%d ",last[m]);
    m -= data[last[m]].weight;
  }
  printf("\n");

  return dp[w];
}

int knapsack3(int n, int w, int *dp, const Item *data, bool put[][W+1]){
  for(int i=0;i<n;++i){
    int weight = data[i].weight;
    int value = data[i].value;
    for(int j=w;j-weight>=0;--j){
      if(dp[j] < dp[j-weight]+value){
        dp[j] = dp[j-weight]+value;
        put[i][j] = true;
      }
    }
  }

  for(int i=n-1, j=w;i>=0;--i){
    if(put[i][j]){
      printf("put %d\n",i);
      j -= data[i].weight;
    }
  }

  return dp[w];
}

int main(){
  int cost[N] = {60,100,120};
  int weight[N] = {10,20,30};
  for(int i=0;i<N;++i){
    printf("item %d: (v:%d, w:%d)\n",i,cost[i],weight[i]);
  }

  int dp[N+1][W+1] = {0};
  Item data[3];
  for(int i=0;i<N;++i){
    data[i].value = cost[i];
    data[i].weight = weight[i];
  }
  printf("0/1 top: %d\n",knapsack1(N,W,dp,data));

  int dp2[W+1] = {0};
  printf("0/1 bot: %d\n",knapsack2(N,W,dp2,data));

  int dp2u[W+1] = {0};
  printf("Unbound: %d\n",knapsack2U(N,W,dp2u,data));

  int dp3[W+1] = {0};
  bool put[N][W+1];
  memset(put, false, sizeof(put));
  printf("0/1 bot, put: %d\n",knapsack3(N,W,dp3,data,put));


  return 0;
}
