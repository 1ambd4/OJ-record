#include <iostream>
using namespace std;

int _pow(int a, int b, int t) {
    int ans = a;
    for (int i = 0; i < t; ++i) {
        ans *= b;
    }
    return ans;
}

int main(void) {
#ifdef LOCAL
    freopen("1.2.7.in", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, a, b, ans;
    char ch;
    while (cin >> n) {
        ans = 0;
        for (int i = 0; i < n; ++i) {
            cin >> a >> ch >> b >> ch;
            int _t = 0;
            while (a != 0) {
                ans += _pow(a % 10, b, _t++);
                a /= 10;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
