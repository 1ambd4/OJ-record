#include <iostream>
using namespace std;

using ll = long long;

inline ll gcd(ll a, ll b) {
    while (b != 0) {
        ll t = a % b;
        a = b;
        b = t;
    }
    return a;
}

inline ll lcm(ll a, ll b) {
    return a * b / gcd(a, b);
}

int main(void) {
#ifdef LOCAL
    freopen("2028.in", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n, t, a;
    while (cin >> n) {
        cin >> t;
        for (int i = 1; i < n; ++i) {
            cin >> a;
            t = lcm(t, a);
        }
        cout << t << endl;
    }
    return 0;
}
