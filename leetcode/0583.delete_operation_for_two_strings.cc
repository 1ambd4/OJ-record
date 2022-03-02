#include <iostream>
#include <string>

using namespace std;

int MinimumDistance(string word1, string word2)
{
    // dp[i][j]: word1[0...i]和word2[0...j]最少需要删除多少次
    int dp[word1.size()+1][word2.size()+1];
    memset(dp, 0, sizeof(dp));

    for (int i = 1; i <= word1.size(); ++i) dp[i][0] = i;
    for (int i = 1; i <= word2.size(); ++i) dp[0][i] = i;

    for (int i = 1; i <= word1.size(); ++i) {
        for (int j = 1; j <= word2.size(); ++j) {
            // word1[i] == word[j]，则不用增加删除次数
            // 否则要么删wrod1[i]，要么删word2[j]，显然删其中小的
            if (word1[i-1] == word2[j-1]) {
                dp[i][j] = dp[i-1][j-1];
            } else {
                dp[i][j] = min(dp[i][j-1], dp[i-1][j]) + 1;
            }
        }
    }

    return dp[word1.size()][word2.size()];
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
