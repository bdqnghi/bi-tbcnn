#include <bits/stdc++.h>
using namespace std;

int dp[2001][2001]; // dp[i][j] is value of sack with i items already considered and j capacity left

int main() {
  int s, n;
  int ta, tb;
  vector<int> wt, val; // w: size/weight array, v: value array

  cin >> s >> n;

  for(int i=0; i<n; i++) {
    cin >> ta >> tb;
    wt.push_back(ta);
    val.push_back(tb);
  }

  // base case
  for(int i=0; i<n; i++)
    dp[i][0] = dp[0][i] = 0;

  // the shiz
  for(int i=1; i<=n; i++) { // item loop
    for(int w=1; w<=s; w++) { // weight loop
      if(wt[i-1] <= w) {
        dp[i][w] = max(
          val[i-1]+dp[i-1][w-wt[i-1]], // item i included
          dp[i-1][w] // item i not included
        );
      } else dp[i][w] = dp[i-1][w];
    }
  }

  /*
  when you want to put initialization inside the main loop
  for(int i=0; i<=n; i++) { // item loop
    for(int wt=0; wt<=s; wt++) { // weight loop
      if(w == 0 or i == 0)
        dp[i][w] = 0; // base case
      else if(wt[i-1] <= w) {
        dp[i][w] = max(
          val[i-1]+dp[i-1][w-wt[i-1]], // item i included
          dp[i-1][w] // item i not included
        )
      } else dp[i][w] = dp[i-1][w];
  }
  */

  cout << dp[n][s] << endl;

  return 0;
}
