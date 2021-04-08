#include <iostream>
using namespace std;

int a[6]{100, 50, 10, 5, 2, 1};

int main(void) {
#ifdef LOCAL
    freopen("2021.in", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, t, ans;
    while (cin >> n) {
        if (n == 0) break;
        ans = 0;
        for (int i = 0; i < n; ++i) {
            cin >> t;
            for (int i = 0; i < 6; ++i) {
                ans += t / a[i];
                t = t - t / a[i] * a[i];
            }
        }
        cout << ans << endl;
    }
    return 0;
}
