#include <iostream>
#include <cstring>
#include <vector>
#include <cassert>
using namespace std;

int minimal_edit_distance(string& word1, string& word2) {
    int m = word1.size(), n = word2.size();
    vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

    for (int i = 0; i <= m; ++i) dp[i][0] = i;
    for (int j = 0; j <= n; ++j) dp[0][j] = j;

    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (word1[i-1] == word2[j-1]) dp[i][j] = dp[i-1][j-1];
            else {
                dp[i][j] = min(min(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1]) + 1;
            }
        }
    }

    return dp[m][n];
}

int main(void) {
    string s1_case1 = "horse";
    string s2_case1 = "ros";
    cout << minimal_edit_distance(s1_case1, s2_case1) << endl;

    string s1_case2 = "intention";
    string s2_case2 = "execution";
    cout << minimal_edit_distance(s1_case2, s2_case2) << endl;

    return 0;
}
