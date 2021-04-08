#include <iostream>
#include <cmath>
using namespace std;

constexpr int MAX = 1e8 + 10;
unsigned long long dp[MAX], _t, cnt;

int main(void) {
#ifdef LOCAL
    freopen("2.2.1.in", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, ans;
    dp[0] = 0; dp[1] = 1;
    for (int i = 2; i < MAX; ++i) {
        dp[i] = dp[i-1] + dp[i-2];
    }
    while (cin >> n) {
        if (dp[n] <= 9999) ans = dp[n];
        else {
            _t = dp[n], cnt = 1;
            while (_t /= 10) {
                cnt++;
            }
        }
        printf("%d\n", int(dp[n] / pow(10, cnt-4)));
    }
    return 0;
}