#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

int dp[10005];
struct Things {
    int cost, value;
}things[1005];

int main(void) {
    int n, m;
    while (cin >> n >> m) {
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < n; i++) {
            cin >> things[i].value >> things[i].cost;
        }

        for (int i = 0; i < n; i++) {
            for (int j = things[i].value; j <= m; j++) {
                dp[j] = max(dp[j], dp[j-things[i].value] + things[i].cost);
            }
        }

        cout << dp[m] << endl;
    }
    return 0;
}
