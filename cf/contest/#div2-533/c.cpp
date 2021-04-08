#include <iostream>
using namespace std;

typedef long long ll;

const ll MOD = 1e9 + 7;
const int MAX = 2e5 + 10;
ll dp[MAX][3], cnt[3];

ll n, l, r;

int main(void) {
#ifdef LOCAL
    freopen("c.in", "r", stdin);
#endif
    cin >> n >> l >> r;

    cnt[0] = cnt[1] = cnt[2] = (r - l + 1) / 3;
    if (((r - l + 1) % 3) == 1) cnt[l%3]++;
    if (((r - l + 1) % 3) == 2) { cnt[l%3]++; cnt[(l+1) % 3]++; }

    dp[1][0] = cnt[0];
    dp[1][1] = cnt[1];
    dp[1][2] = cnt[2];
    for (ll i = 2; i <= n; ++i) {
        dp[i][0] = (dp[i-1][0] * cnt[0] + dp[i-1][1] * cnt[2] + dp[i-1][2] * cnt[1]) % MOD;
        dp[i][1] = (dp[i-1][0] * cnt[1] + dp[i-1][1] * cnt[0] + dp[i-1][2] * cnt[2]) % MOD;
        dp[i][2] = (dp[i-1][0] * cnt[2] + dp[i-1][1] * cnt[1] + dp[i-1][2] * cnt[0]) % MOD;
    }
    cout << dp[n][0] << endl;
    return 0;
}
