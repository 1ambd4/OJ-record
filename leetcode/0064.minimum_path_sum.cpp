#include <iostream>
#include <vector>

using namespace std;

// 优化成一维（滚动数组
int min_path_sum(vector<vector<int>>& grid)
{
    int m = grid.size(), n = grid[0].size();
    vector<int> dp(grid[0]);

    dp[0] = grid[0][0];
    for (int i = 1; i < n; ++i) dp[i] += dp[i-1];

    for (int i = 1; i < m; ++i) {
        dp[0] += grid[i][0];
        for (int j = 1; j < n; ++j) {
            dp[j] = min(dp[j], dp[j-1]) + grid[i][j];
        }
    }

    return dp[n-1];
}

int _min_path_sum(vector<vector<int>>& grid)
{
    int m = grid.size(), n = grid[0].size();
    vector<vector<int>> dp(m, vector<int>(n, 0));

    dp[0][0] = grid[0][0];
    for (int i = 1; i < m; ++i) dp[i][0] = dp[i-1][0] + grid[i][0];
    for (int j = 1; j < n; ++j) dp[0][j] = dp[0][j-1] + grid[0][j];

    for (int i = 1; i < m; ++i) {
        for (int j = 1; j < n; ++j) {
            dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i][j];
        }
    }

    return dp[m-1][n-1];
}

int main()
{
    vector<vector<int>> grid1 {{1,3,1},{1,5,1},{4,2,1}};
    cout << min_path_sum(grid1) << endl;

    vector<vector<int>> grid2 {{1,2,3},{4,5,6}};
    cout << min_path_sum(grid2) << endl;
    return 0;
}

