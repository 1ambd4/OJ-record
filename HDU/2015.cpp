#include <iostream>
using namespace std;

int main(void) {
#ifdef LOCAL
    freopen("2015.in", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    while (cin >> n >> m) {
        int t = n / m, a = m + 1;
        for (int i = 0; i < t; ++i) {
            if (i == 0) cout << (m + 1) + (2* m * i);
            else cout << " " << (m + 1) + (2* m * i);
        }
        if (n % m != 0) {
            cout << " " << 2 * (n / m * m + 1) + (n % m - 1) << endl;
        }
        else {
            cout << endl;
        }
    }
    return 0;
}
