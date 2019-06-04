#include <iostream>
#include <cstring>
using namespace std;

typedef long long ll;
const ll MAX = 10000 + 10;

ll a[MAX], p[65], m, cnt;   // cnt 为线性基的大小 

void gauss(ll n) {
    memset(p, 0, sizeof(p));
    for (ll i = 1; i <= n; ++i) {
        for (ll j = 63; j >= 0; --j) if ((a[i]>>j) & 1) {
            if (p[j]) {
                a[i] ^= p[j];
            }
            else {
                p[j] = a[i];
                break;
            }
        }
    }
    cnt = 0;
    for (ll i = 0; i <= 63; ++i) if (p[i]) cnt++;
}

void solve() {
    for (ll i = 63; i >= 0; --i) {
        if (!p[i]) continue;
        for (int j = i + 1; j <= 65; ++j) {
            if ((p[j]>>i) & 1) p[j] ^= p[i];
        }
    }
    m = 0;
    for (ll i = 0; i <= 63; ++i) if (p[i]) {
        p[m++] = p[i];
    }
}

int main(void) {
#ifdef LOCAL
    freopen("3949.in", "r", stdin);
#endif
    ll T, n, q, k, ans;
    cin >> T;
    for (ll _T = 1; _T <= T; ++_T) {
        cout << "Case #" << _T << ":" << endl;
        cin >> n;
        for (ll i = 1; i <= n; ++i) cin >> a[i];
        gauss(n);
        solve();
        cin >> q;
        while (q--) {
            cin >> k;
            if (n != m) k--;
            if (k >= (1LL<<m)) cout << "-1" << endl;
            else {
                ans = 0;
                for (ll i = 0; i <= 63; ++i) if ((k>>i) & 1) {
                    ans ^= p[i];
                }
                cout << ans << endl;
            }
        }
    }
    return 0;
}