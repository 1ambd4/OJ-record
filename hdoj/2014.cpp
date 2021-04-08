#include <iostream>
#include <algorithm>
using namespace std;

constexpr int MAX = 100 + 5;
int s[MAX];

int main(void) {
#ifdef LOCAL
    freopen("2014.in", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, ans;
    while (cin >> n) {
        ans = 0;
        for (int i = 0; i < n; ++i) {
            cin >> s[i];
        }
        sort(s, s + n);
        for (int i = 1; i < n - 1; ++i) {
            ans += s[i];
        }
        printf("%.2f\n", ans/(n - 2.0));
    }
    return 0;
}
