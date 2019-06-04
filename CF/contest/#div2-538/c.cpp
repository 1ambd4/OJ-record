#include <iostream>
#include <cmath>
using namespace std;

typedef long long ll;

const int MAX = 2e6 + 10;

ll num[MAX], cnt[MAX], tot = 0;
ll n, b;
void factorize(ll u) {
    ll _t = sqrt(u + 0.5);
    for (ll i = 2; i <= _t; ++i) if (u % i == 0) {
            num[tot] = i;
            cnt[tot] = 0;
            while (u %i == 0) {
                u /= i;
                cnt[tot]++;
            }
            tot++;
    }
    if (u != 1) {
        num[tot] = u;
        cnt[tot] = 1;
        tot++;
    }
}

ll coun(ll n, ll p) {
    ll ans = 0;
    for ( ; n;  n /= p) ans += n / p;//  cout << n << " " << p << " " << ans << endl;
    return ans;
}

int main(void) {
#ifdef LOCAL
freopen("c.in", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll ans = (1LL<<60);
    cin >> n >> b;
    factorize(b);
    // if (i < tot) cout << "fuck" << endl;
    for (ll i = 0; i < tot; ++i) {
        ans = min(ans, coun(n, num[i])/cnt[i]);
        //cout << n << " " << num[i] / cnt[i] << " " << num[i] << " " << cnt[i] << endl;
    }
    cout << ans << endl;
    return 0;
}