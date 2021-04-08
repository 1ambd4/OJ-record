#include <iostream>
#include <algorithm>
using namespace std;

constexpr int MAX = 100 + 10;
int a[MAX];

int main(void) {
#ifdef LOCAL
    freopen("2019.in", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    while (cin >> n >> m) {
        if (n == 0 && m == 0) break;
        a[0] = m;
        for(int i = 1; i <= n; ++i) {
            cin >> a[i];
        }
        sort(a, a + n + 1);
        for (int i = 0; i <= n; ++i) {
            if (i == 0) cout << a[i];
            else cout << " " << a[i];
        }
        cout << endl;
    }
    return 0;
}
