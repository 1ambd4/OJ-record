#include <iostream>
#include <cmath>
using namespace std;

int main(void) {
#ifdef LOCAL
    freopen("2009.in", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    double ans, tmp;
    while (cin >> n >> m) {
        ans = tmp = n;
        for (int i = 1; i < m; ++i) {
            ans += (tmp = sqrt(tmp));
        }
        printf("%.2f\n", ans);
    }
    return 0;
}
