#include <iostream>
using namespace std;

typedef long long ll;

int C(int m, int n) {
    ll ans = 1;
    for (int i = 1; i <= n; ++i) {
        ans = ans * m-- / i;
    }
    return ans;
}

int main(void) {
#ifdef LOCAL
   // freopen("1664.in", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    int T, m, n;
    while (0) {
        cin >> m >> n;
        cout << C(m, n) / m << endl;
    }
    cout << C(8, 3) / (8 - 1) << endl;
    return 0;
}
