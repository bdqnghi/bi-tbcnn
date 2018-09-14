#include <iostream>
#include <vector>
using namespace std;

int optimal_weight(int W, int N, const vector<int> &w) {
  vector<vector<int>> s(N+1, vector<int>(W+1));
  for(int i=1; i<=N; i++) for(int j=1; j<=W; j++) 
    s[i][j] = (j-w[i] >= 0 ? max(s[i-1][j], s[i-1][j-w[i]] + w[i]) : s[i-1][j]);
  return s[N][W];
}

int main() {
  int n, W; cin >> W >> n;
  vector<int> w(n+1);
  for (int i=1; i<=n; i++) cin >> w[i];
  cout << optimal_weight(W, n, w) << endl;
}
/*
recursive might be easier
*/