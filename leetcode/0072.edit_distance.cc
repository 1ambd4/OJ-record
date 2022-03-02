#include <iostream>
#include <cstring>
#include <vector>
#include <cassert>
using namespace std;

// dp[i][j] -- s1[0...i]和s2[0...j]的最小编辑距离
// 如果当前字符相等，则dp[i][j] = dp[i-1][j-1]，即编辑距离不变
// 如果当前字符不相等，dp[i][j] = min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1])，即分别对应增删改操作

int minimal_edit_distance(string& word1, string& word2) {
    int len1 = word1.length(), len2 = word2.length();
    int dp[len1+1][len2+1];

    // 两个串都空的时候，不需要进行编辑，也即编辑距离为0
    dp[0][0] = 0;

    for (int i = 1; i <= len1; ++i) dp[i][0] = i;
    for (int i = 1; i <= len2; ++i) dp[0][i] = i;

    for (int i = 1; i <= len1; ++i) {
        for (int j = 1; j <= len2; ++j) {
            if (word1[i-1] == word2[j-1]) {
                dp[i][j] = dp[i-1][j-1];
            }
            else {
                dp[i][j] = min(dp[i][j-1]+1, min(dp[i-1][j]+1, dp[i-1][j-1]+1));
            }
        }
    }

    return dp[len1][len2];
}

int main(void) {
    string s1_case1 = "horse";
    string s2_case1 = "ros";
    assert(minimal_edit_distance(s1_case1, s2_case1) == 3);
    
    string s1_case2 = "intention";
    string s2_case2 = "execution";
    assert(minimal_edit_distance(s1_case2, s2_case2) == 5);

    cout << "Accepted by the test example!" << endl;

    return 0;
}