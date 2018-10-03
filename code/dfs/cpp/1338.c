#include <cstdio>

int n,k;
const int MAX_N = 20;
int a[MAX_N];

void read();
void solve();

bool dfs(int i, int sum){

  if (i == n) return sum == k;

  // case; don't use a[i]
  if (dfs(i+1, sum)) return true;

  // case; use a[i]
  if (dfs(i+1, sum + a[i])) return true;

  // failure 
  return false;
}

int main(){
  read();
  solve();
  return 0;
}

void read(){
  scanf("%d", &n);
  for(int i=0; i<n; i++){
    scanf("%d", &a[i]);
  }
  scanf("%d", &k);  
}

void solve(){

  if (dfs(0,0)) printf("Yes\n");
  else printf("No\n");
}
