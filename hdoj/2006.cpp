#include <iostream>
using namespace std;

int main(void) {
#ifdef LOCAL
    freopen("2006.in", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, a;
    long long ans;
    while (cin >> n) {
        ans = 1;
        while (n--) {
            cin >> a;
            if (a & 1) ans *= a;
        }
        cout << ans << endl;
    }
    return 0;
}
