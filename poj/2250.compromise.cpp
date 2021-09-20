#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

const int MAX = 1e2 + 10;
string arr1[MAX], arr2[MAX];
int dp[MAX][MAX];

int LCS(string arr1[], int len1, string arr2[], int len2) {
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

void dfs(int u, int v) {
	if(!u || !v) return ;
    if (arr1[u-1] == arr2[v-1]) {
        dfs(u - 1, v - 1);
        cout << arr1[u-1] << " ";
    }
    else {
        if (dp[u-1][v] > dp[u][v-1]) dfs(u-1, v);
        else dfs(u, v-1);
    }
}

// 这题多组输入真他妈毒瘤
int main(void) {
#ifdef LOCAL
    freopen("2250.in", "r", stdin);
#endif
Begin:
    int len1 = 0, len2 = 0;
    while (cin >> arr1[len1++]) if (arr1[len1-1] == "#") {
        arr1[--len1] = "\0";
        break;
    }

    while (cin >> arr2[len2++]) if (arr2[len2-1] == "#") {
        arr2[--len2] = "\0";
        break;
    }

    LCS(arr1, len1, arr2, len2);
    dfs(len1, len2);
    cout << endl;
    //cout << len1 << " " << len2 << endl;
    //for (int i = 0; i <= len2; ++i) cout << arr2[i] << " "; cout << endl;
    //if (cin.peek() != EOF) goto Begin;
    getchar();
    if (cin.peek() != EOF) goto Begin;
    return 0;
}