#include <iostream>
#include <string>

using namespace std;

// 最长公共子序列
int MinimumDistance(string word1, string word2)
{
    int dp[word1.size()+1][word2.size()+1];
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= word1.size(); ++i) {
        for (int j = 1; j <= word2.size(); ++j) {
             if (word1[i-1] == word2[j-1]) {
                 dp[i][j] = dp[i-1][j-1] + 1;
             } else {
                 dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
             }
        }
    }
    return word1.size() + word2.size() - 2*dp[word1.size()][word2.size()];
}

int main(void)
{
    cout << MinimumDistance("sea", "eat") << endl;
    cout << MinimumDistance("leetcode", "etco") << endl;
    // 是子序列啊，不是子串
    cout << MinimumDistance("park", "spake") << endl;
    cout << MinimumDistance("intention", "execution") << endl;
    return 0;
}
