#include <unordered_map>
#include "knapsack.h"

using std::unordered_map;
using std::vector;

// Knapsack function that assumes each item has infinit copies. It
// returns the max value. *items* is a list of avaiable items, and *W*
// is the knapsack capacity.
int KnapsackRepeat(const vector<Item>& items,
                   int W,
                   unordered_map<int, int>& dp) {
  if (dp.find(W) != dp.end()) {
    return dp[W];
  }
  int value = 0;
  for (const Item& item : items) {
    if (item.weight <= W) {
      int cur_value = item.value +
          KnapsackRepeat(items, W-item.weight, dp);
      if (cur_value > value) {
        value = cur_value;
      }
    }
  }
  dp[W] = value;
  return value;
}

// Knapsack function that assumes each item has only one copy. It
// returns the max value. *items* is a list of avaiable items, and *W*
// is the knapsack capacity.
int KnapsackNonrepeat(const vector<Item>& items,
                      int W,  // total capacity
                      int k,  // {1,2,...,k} items can choose. 1-based index.
                      unordered_map<int, int>& dp) {
  if (dp.find(W) != dp.end()) {
    return dp[W];
  }
  if (k == 0) {
    // Nothing can pick.
    return 0;
  }
  const Item& item = items[k-1];
  // Solution for not taking kth item.
  int value = KnapsackNonrepeat(items, W, k-1, dp);
  if (item.weight <= W) {
    // Solution for taking kth item.
    int cur_value = item.value +
        KnapsackNonrepeat(items, W-item.weight, k-1, dp);
    if (cur_value > value) {
      value = cur_value;
    }
  }
  dp[W] = value;
  return value;
}

int Knapsack(const std::vector<Item>& items, int W, bool allow_repeat) {
  unordered_map<int, int> dp;
  if (allow_repeat) return KnapsackRepeat(items, W, dp);
  return KnapsackNonrepeat(items, W, items.size(), dp);
}
