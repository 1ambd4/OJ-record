#include <iostream>
#include <vector>

using namespace std;

int unique_paths(int m, int n)
{
    vector<int> dp(n, 1);

    for (int i = 1; i < m; ++i) {
        for (int j = 1; j < n; ++j) {
            // 此时dp[i][j]里的数据刚好是dp[i-1][j]
            // 因而可以将空间优化成一维
            dp[j] += dp[j-1];
        }
    }

    return dp[n-1];
}

// 很经典的题了
int _unique_paths(int m, int n)
{
    vector<vector<int>> dp(m, vector<int>(n, 0));

    for (int i = 0; i < m; ++i) dp[i][0] = 1;
    for (int j = 0; j < n; ++j) dp[0][j] = 1;

    for (int i = 1; i < m; ++i) {
        for (int j = 1; j < n; ++j) {
            dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
    }

    // return dp[m][n];
    return dp[m-1][n-1];
}

int main()
{
    cout << unique_paths(3, 7) << endl;
    cout << unique_paths(3, 2) << endl;
    return 0;
}

