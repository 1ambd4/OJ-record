#include <iostream>
using namespace std;

int main(void) {
#ifdef LOCAL
    freopen("2011.in", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T, n;
    double ans;
    cin >> T;
    while (T--) {
        ans = 0;
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            if (i & 1) ans += 1.0 /  i;
            else ans -= 1.0 / i;
        }
        printf("%.2f\n", ans);
    }
    return 0;
}
