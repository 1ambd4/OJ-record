#include <iostream>
using namespace std;

const int MAX = 100000 + 10;
const int INF = 0x3f3f3f3f;
int a[MAX];

int main(void) {
#ifdef LOCAL
    freopen("3061.in", "r", stdin);
#endif
    int T, n, s, l, r, sum;
    cin >> T;
    while (T--) {
        cin >> n >> s;
        int _sum = 0;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            _sum  += a[i];
        }
        if (_sum <= s) {
            cout << "0" << endl;
            continue;
        }
        sum = l = r = 0;
        int mn = INF;
        while (r < n) {
            sum += a[r++];
            while (sum > s) {
                sum -= a[l++];
                mn = min(mn, r - l + 1);
            }
        }
        cout << mn << endl;
    }
    return 0;
}
