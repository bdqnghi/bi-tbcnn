#include <iostream>
#include <vector>
using namespace std;

int knapsack_1(int weight, int* wt, int* val, int index) {
  if (weight == 0 || index == 0) {
    return 0;
  }

  if (wt[index - 1] > weight) {
    return knapsack_1(weight, wt, val, index - 1);
  } else {
    return max(val[index - 1] + knapsack_1(weight - wt[index - 1], wt, val, index - 1),
             knapsack_1(weight, wt, val, index - 1));
  }
}

int knapsack_2(int weight, int* wt, int* val, int n) {
  vector<vector<int> > val_table(n + 1, vector<int>(weight + 1, 0));
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= weight; j++) {
      if (i == 0 | j == 0) {
        val_table[i][j] = 0;
      } else if (wt[i - 1] <= j) {
        val_table[i][j] = 
          max(val[i - 1] + val_table[i - 1][j - wt[i - 1]], val_table[i - 1][j]);
      } else {
        val_table[i][j] = val_table[i - 1][j];
      }
    }
  }

  return val_table[n][weight];
}

int main() {
  int w;
  cin>>w;
  int val[3] = {60, 100, 120};
  int wt[3] = {10, 20, 30};
  cout<<knapsack_1(w, wt, val, 3)<<" "<<knapsack_2(w, wt, val, 3)<<endl;

  return 0;
}
