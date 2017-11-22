#include <iostream>
#include <vector>

using std::vector;

int optimal_weight(int W, const vector<int> &w) {
  //write your code here
  int n = w.size();
  int rows = n + 1;
  int cols = W + 1;
  vector<vector<int>> value;
  value.resize(rows);
  for (int i = 0; i < rows; ++i){
	  value[i].resize(cols);
  }

  for (int i=1; i < rows; i++){
	  for (int j=1; j < cols; j++){
		  value[i][j] = value[i-1][j];
		  if (w[i-1] <= j){
			  int val = value[i-1][j-w[i-1]] + w[i-1];
			  if (value[i][j] < val){
				  value[i][j] = val;
			  }
		  }
	  }
  }

  int maxweight = value[rows-1][cols-1];
  return maxweight;
}

int main() {
  int n, W;
  std::cin >> W >> n;
  vector<int> w(n);
  for (int i = 0; i < n; i++) {
    std::cin >> w[i];
  }
  std::cout << optimal_weight(W, w) << '\n';
  system("pause");
}
