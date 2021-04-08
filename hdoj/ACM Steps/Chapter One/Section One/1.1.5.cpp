#include <iostream>
using namespace std;

int main(void) {
#ifdef LOCAL
    freopen("1.1.5.in", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T, n, t, s;
    cin >> T;
    while (T--) {
        s = 0;
        cin >> n;
        while (n--) {
            cin >> t;
            s += t;
        }
        cout << s << endl;
    }
    return 0;
}
