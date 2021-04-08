#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
#ifdef LOCAL
    freopen("2039.in", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    double a[3];
    cin >> T;
    while (T--) {
        cin >> a[0] >> a[1] >> a[2];
        sort(a, a + 3);
        if (a[0] + a[1] <= a[2] || a[2] - a[1] >= a[0]) cout << "NO" << endl;
        else cout << "YES" << endl;
    }
    return 0;
}
