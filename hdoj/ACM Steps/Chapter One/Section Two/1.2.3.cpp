#include <iostream>
using namespace std;

int main(void) {
#ifdef LOCAL
    freopen("1.2.3.in", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, u, d;
    while (cin >> n >> u >> d) {
        int cnt = 0;
        if (n == 0) break;
        for ( ; n > 0; ) {
            n -= u;
            cnt++;
            if (n <= 0) break;
            n += d;
            cnt++;
        }
        cout << cnt << endl;
    }
    return 0;
}
