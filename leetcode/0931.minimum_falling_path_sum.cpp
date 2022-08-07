#include <iostream>
#include <vector>
#include <limits>

#include "leetcode.h"

using namespace std;

int min_falling_path_sum(vector<vector<int>>& matrix)
{
    vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size()+2, numeric_limits<int>::max()));

    for (int j = 1; j <= matrix.size(); ++j) {
        dp[0][j] = matrix[0][j-1];
    }

    auto min_of_three = [](int a, int b, int c) {
        return min(a, min(b, c));
    };

    for (int i = 1; i < dp.size(); ++i) {
        for (int j = 1; j < dp[0].size()-1; ++j) {
            dp[i][j] = matrix[i][j-1] + min_of_three(dp[i-1][j-1], dp[i-1][j], dp[i-1][j+1]);
        }
    }

    int res = numeric_limits<int>::max();
    for (int i = 1; i < dp[0].size()-1; ++i) {
        res = min(res, dp[dp.size()-1][i]);
    }

    return res;
}

int main()
{
    vector<vector<int>> matrix1 { {2, 1, 3},
                                  {6, 5, 4},
                                  {7, 8, 9} };
    cout << min_falling_path_sum(matrix1) << endl;

    vector<vector<int>> matrix2 { {-19, 57},
                                  {-40, -5} };
    cout << min_falling_path_sum(matrix2) << endl;
    return 0;
}

