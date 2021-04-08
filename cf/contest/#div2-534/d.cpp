#include <iostream>
#include <cstring>
using namespace std;

typedef long long ll;

char ask(ll l, ll r) {
    cout << "? " << l << " " << r << endl;
    fflush(stdout);
    char ch;
    cin >> ch;
    return ch;
}

void solve() {
    int p = 0;
    for (int i = 0; i < 32; ++i) {
        if (ask(i == 0 ? 0 : (1LL<<(i-1)), 1LL<<i) == 'x') {
            p = i - 1;
            break;
        }
    }
    ll ans = 0;
    if (p != -1) {
        ans = 1 << p;
        for (int i = p - 1; i >= 0; --i) {
            ll y = 1LL << i;
            if (ask(ans, ans + y) == 'y') {
                ans += y;
            }
        }
    }
    cout << "! " << ans + 1 << endl;
}

int main(void) {
#ifdef LOCAL
    freopen("d.in", "r", stdin);
#endif
    std::ios::sync_with_stdio(false);
    string s;
    while (cin >> s) {
        if (s == "end") break;
        solve();
        fflush(stdout);
    }
    return 0;
}