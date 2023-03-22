#include <iostream>
#include <vector>
#include <string>

using namespace std;

// 经典的二维动态规划
bool is_match(string s, string p)
{
    int n = s.size(), m = p.size();
    // dp[i][j]：s[0...i]与p[0...j]是否可以成功匹配
    vector<vector<bool>> dp(n+1, vector<bool>(m+1, false));

    // 处理s为空的情况
    dp[0][0] = true;
    for (int i = 1; i <= m; ++i) {
        if (p[i-1] == '*') {
            dp[0][i] = dp[0][i-2];
        }
    }

    //
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            // 文本串和模式串字符可以匹配上
            if (s[i-1] == p[j-1] || p[j-1] == '.') {
                dp[i][j] = dp[i-1][j-1];
            } else if (p[j-1] == '*') {
                // 模式串*的前一个字符能和文本串的末位匹配上
                if (s[i-1] == p[j-2] || p[j-2] == '.') {
                    // 匹配0次或者多次
                    dp[i][j] = dp[i][j-2] || dp[i-1][j];
                } else {  // 模式串*的前一个字符不能和文本串的末位匹配上
                    dp[i][j] = dp[i][j-2];  // 此时*只能匹配0次
                }
            }
        }
    }

    return dp[n][m];
}

int main()
{
    cout << is_match("aa", "a") << endl;
    cout << is_match("aa", "a*") << endl;
    cout << is_match("ab", ".*") << endl;
    return 0;
}

