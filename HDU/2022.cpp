#include <iostream>
using namespace std;

struct {
    int x, y, v;
}ans;

int main(void) {
#ifdef LOCAL
    freopen("2022.in", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, t;
    while (cin >> n >> m) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> t;
                if (i == 0 && j == 0) { ans.x = i; ans.y = j; ans.v = t; }
                if (abs(t) > abs(ans.v)) { ans.x = i; ans.y = j; ans.v = t; }
            }
        }
        cout << ans.x + 1 << " " << ans.y + 1 << " " << ans.v << endl;
    }
    return 0;
}
