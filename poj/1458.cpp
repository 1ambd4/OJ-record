#include <iostream>
#include <cstring>
using namespace std;

const int MAX = 1e3 + 10;
int dp[MAX][MAX];
char arr1[MAX], arr2[MAX];

int LCS(char arr1[], int len1, char arr2[], int len2) {
    for (int i = 1; i <= len1; ++i) {
        for (int j = 1; j <= len2; ++j) {
            if (arr1[i-1] == arr2[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    return dp[len1][len2];
}

int main(void) {
#ifdef LOCAL
  freopen("1458.in", "r", stdin);
#endif
    while (cin >> arr1 >> arr2) {
        memset(dp, 0, sizeof(dp));
        cout << LCS(arr1, strlen(arr1), arr2, strlen(arr2)) << endl;
        //memset(arr1, 0, sizeof(arr1));
        //memset(arr2, 0, sizeof(arr2));
    }
    return 0;
}