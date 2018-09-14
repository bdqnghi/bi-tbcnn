#include <iostream>
#include <vector>
#include<algorithm>

using namespace std;

int optimal_weight(int W, vector<int> w)
{
  vector<int> c(W+1);
  for(int i = 0;i<W+1;i++)
    c[i]=0;
  for(int i = 0;i<w.size();i++)
    {
        for(int j=W;j>w[i]-1;j--)
          {
            c[j] = max(c[j], c[j-w[i]]+w[i]);
          }
    }
  return c[W];
}

int main()
{
  int n, W;
  cin >> W >> n;
  vector<int> w(n);
  for (int i = 0; i < n; i++)
  {
    cin >> w[i];
  }
  cout << optimal_weight(W, w) << '\n';
}
