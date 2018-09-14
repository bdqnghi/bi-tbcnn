#include <iostream>
#include <vector>

using std::vector;

int optimal_weight(int W, const vector<int> &w, int n) {
  //write your code here
  int current_weight = 0;
  /*for (size_t i = 0; i < w.size(); ++i) {
    if (current_weight + w[i] <= W) {
      current_weight += w[i];
    }
  }*/
  int temp, temp1;
  vector<vector<int> > v;

     for ( i = 1; i <= n; i++)
    {
        <vector<int> > vt;
        for ( j = 1; j <= W; j++)
        {
           temp = v[i - 1][j];
      //     printf("\n i = %d, j = %d, mat[i][j] : %llu and w[i]: %llu", i, j, mat[i][j], w[i]);
           if (j >= w[i])
           {
               temp1 = v[i - 1][ j - w[i]] + w[i];
        //       printf("temp value at i=%d j =%d is : %llu", i , j , temp);
               if (temp > v[i][j])
               {
                   temp = temp1;
               }
           }
           vt.push_back(temp);
        }
        v.push_back(vt);
    }

  current_weight = vt[n][W];
  return current_weight;
}

int main() {
  int n, W;
  std::cin >> W >> n;
  vector<int> w(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> w[i];
  }
  std::cout << optimal_weight(W, w, n) << '\n';
}
