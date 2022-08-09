#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 删完最后两个单词应当都只剩下最长公共子序列部分
// dp[i][j]: 以word1[i]和word2[j]为结尾的最长公共子序列

int minimum_distance(string word1, string word2)
{
    int n = word1.size(), m = word2.size();

    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (word1[i-1] == word2[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            } else {
                dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
            }
        }
    }

    return n + m - 2 * dp[n][m];
}

int main(void)
{
    cout << minimum_distance("sea", "eat") << endl;
    cout << minimum_distance("leetcode", "etco") << endl;
    // 是子序列啊，不是子串
    cout << minimum_distance("park", "spake") << endl;
    cout << minimum_distance("intention", "execution") << endl;
    return 0;
}
