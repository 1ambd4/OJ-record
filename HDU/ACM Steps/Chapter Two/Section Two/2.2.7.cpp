#include <iostream>
using namespace std;

constexpr int MOD = 2009;

inline long long mmul(long long a, long long b) {
    long long lf = a * (b >> 25LL) % MOD * (1LL << 25) % MOD;
    long long rg = a * (b & ((1LL << 25) - 1)) % MOD;
    return (lf + rg) % MOD;
}

int main(void) {
#ifdef LOCAL
    freopen("2.2.7.in", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    long long n, ans;
    while (cin >> n) {
        ans = 1;
        for (int i = 1; i <= n; ++i) {
            ans = mmul(ans, i);
        }
        cout << ans % MOD << endl;
    }
    return 0;
}
