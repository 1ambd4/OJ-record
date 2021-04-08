#include <iostream>
#include <ctime>
using namespace std;

using ll = long long;

ll mod_mul(ll a, ll b, ll mod) {
    ll res = 0;
    while (b) {
        if (b & 1) {
            res = (res + a) % mod;
        }
        a = (a + a) % mod;
        b >>= 1;
    }
    return res;
}

ll mod_pow(ll a, ll n, ll mod) {
    ll res = 1;
    while (n) {
        if (n & 1) {
            res = mod_mul(res, a, mod);
        }
        a = mod_mul(a, a, mod);
        n >>= 1;
    }
    return res;
}

bool miller_rabin(ll n) {
    if (n == 2) return true;
    if (n <  2|| !(n & 1)) return false;

    ll m = n - 1, k = 0;
    while (!(m & 1)) {
        k++;
        m >>= 1;
    }

    for (int i = 1; i <= 10; ++i) {
        ll a = rand() % (n - 1) + 1;
        ll x = mod_pow(a, m, n), y;
        for (int j = 1; j <= k; ++j) {
            y = mod_mul(x, x, n);
            if (y == 1 && x != 1 && x != n-1) {
                return false;
            }
            x = y;
        }
        if (y != 1) return false;
    }
    return true;
}

int main(void) {
#ifdef LOCAL
    freopen("2.1.2.in", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    srand(time(NULL));
    int n, t, cnt;
    while (cin >> n) {
        cnt = 0;
        while (n--) {
            cin >> t;
            if (miller_rabin(t)) cnt++;
        }
        cout << cnt << endl;
    }
    return 0;
}