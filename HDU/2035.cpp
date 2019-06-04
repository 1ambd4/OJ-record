#include <iostream>
using namespace std;

int main(void) {
#ifdef LOCAL
    freopen("2035.in", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long a, b, t;
    while (cin >> a >> b) {
        t = a;
        if (a == 0 && b == 0) break;
        for (int i = 0; i < b - 1; ++i) {
            a *= t;
            a %= 100000;
        }
        cout << a % 1000 << endl;
    }
    return 0;
}
