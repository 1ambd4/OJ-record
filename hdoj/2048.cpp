#include <iostream>
using namespace std;

int dp[25];
int pd[25];

int main(void) {
#ifdef LOCAL
    freopen("2048.in", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    dp[1] = 0; dp[2] = 1; dp[3] = 2;
    pd[1] = 1; pd[2] = 2; pd[3] = 6;
    for (int i = 4; i < 25; ++i) {
        dp[i] = (dp[i-1] + dp[i-2]) * (i-1);
        pd[i] = pd[i-1] * i;
    }
    int T, n;
    cin >> T;
    while (T--) {
        cin >> n;
        printf("%.2f%%\n", (double)dp[n] / pd[n] * 100);
    }
    return 0;
}
