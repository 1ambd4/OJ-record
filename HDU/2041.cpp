#include <iostream>
using namespace std;

int dp[50];

int main(void) {
#ifdef LOCAL
    freopen("2041.in", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T, n;
    dp[1] = 1, dp[2] = 1;
    for (int i = 3; i < 50; ++i) {
        dp[i] = dp[i-1] + dp[i-2];
    }
    cin >> T;
    while (T--) {
        cin >> n;
        cout << dp[n] << endl;
    }
    return 0;
}
