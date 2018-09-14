#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int knapsack(vector<int> &weight, vector<int> &value, int max_capacity)
    {
        int n = weight.size();
        vector<vector<int>> dp(n+1, vector<int>(max_capacity+1, 0));
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=max_capacity;j++)
            {
                if(weight[i-1]>j)
                {
                    dp[i][j] = dp[i-1][j];
                }
                else
                {
                    dp[i][j] = max(dp[i-1][j], dp[i-1][j-weight[i-1]]+value[i-1]);
                }
            }
        }
        return dp[n][max_capacity];
    }
};


int main(int argc, char *argv[])
{
    vector<int> weight = {1, 2, 5, 6, 7, 9};
    vector<int> value = {1, 6, 18, 22, 28, 36};
    Solution s;
    int max_value = s.knapsack(weight, value, 20);
    return 0;
}
