#include <bits/stdc++.h>

using namespace std;

int n;
set<long long> seen;

void dfs(string s, char x, char y) {
  long long v = atoll(s.c_str());

  if (v > n || v == 0 || seen.count(v))
    return;
  seen.insert(v);

  string sx(1,x), sy(1,y);
  dfs(s+sx, x, y);
  dfs(sx+s, x, y);
  dfs(sy+s, x, y);
  dfs(s+sy, x, y);
}

int main() {
  scanf("%d", &n);

  for (char x = '0'; x <= '9'; x++) {
    for (char y = '0'; y <= '9'; y++) {
      string sx(1,x), sy(1,y);
      dfs(sx, x, y);
      dfs(sy, x, y);
      dfs(sy+sx, x, y);
      dfs(sx+sy, x, y);
    }
  }

  printf("%d\n", seen.size());

  return 0;
}
