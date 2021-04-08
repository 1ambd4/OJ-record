#include <iostream>
using namespace std;

int main(void) {
#ifdef LOCAL
    freopen("1.2.1.in", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    while (cin >> n) {
        if (n == 0) break;
        int _t = 0, t, _n = n, cnt = 0;
        while (n--) {
            cin >> t;
            int __t = t - _t;
            cnt += (abs(4 * __t) + (__t > 0 ? 2 * __t : 0));
            _t = t;
        }
        cout << cnt + 5 * _n << endl;
    }
    return 0;
}
