#include <iostream>
using namespace std;

constexpr int MAX = 55;
long long dp[MAX];

int main(void) {
#ifdef LOCAL
    freopen("2046.in", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    dp[1] = 1; dp[2] = 2;
    for (int i = 3; i < MAX; ++i) {
        dp[i] = dp[i-1] + dp[i-2];
    }
    int n;
    while (cin >> n) {
        cout << dp[n] << endl;
    }
    return 0;
}
