#include <iostream>
using namespace std;

int main(void) {
#ifdef LOCAL
    freopen("2042.in", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T, n;
    cin >> T;
    while (T--) {
        int ans = 3;
        cin >> n;
        for (int i = 0; i < n; ++i) {
            ans = (ans - 1) * 2;
        }
        cout << ans << endl;
    }
    return 0;
}
