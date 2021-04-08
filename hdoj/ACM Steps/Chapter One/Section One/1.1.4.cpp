#include <iostream>
using namespace std;

int main(void) {
#ifdef LOCAL
    freopen("1.1.4.in", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, t, s;
    while (cin >> n) {
        if (n == 0) break;
        s = 0;
        while (n--) {
            cin >> t;
            s += t;
        }
        cout << s << endl;
    }
    return 0;
}
