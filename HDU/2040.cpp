#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

constexpr int MAX = 10000;
int fa[MAX], fb[MAX];

int main(void) {
#ifdef LOCAL
    freopen("2040.in", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T, a, b, cnta, cntb, t;
    long suma, sumb;
    cin >> T;
    while(T--) {
        cnta = cntb = suma = sumb = 0;
        cin >> a >> b;
        t = sqrt(a + 0.5);
        for (int i = 1; i <= t; ++i) if (a % i == 0) {
            fa[cnta++] = i;
            fa[cnta++] = a / i;
        }
        t = sqrt(b + 0.5);
        for (int i = 1; i <= t; ++i) if (b % i == 0) {
            fb[cntb++] = i;
            fb[cntb++] = b / i;
        }
        // cout << cnta << " " << cntb << endl;
        for (int i = 0; i < cnta;  ++i) {
            suma += fa[i];
        }
        for (int i = 0; i < cntb;  ++i) {
            sumb += fb[i];
        }
        //cout << suma << " " << sumb << endl;
        if (suma == sumb) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}
