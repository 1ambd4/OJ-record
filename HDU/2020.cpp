#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

bool cmp(int a, int b) {
    return abs(a) > abs(b);
}

constexpr int MAX = 100 + 10;
int a[MAX];

int main(void) {
#ifdef LOCAL
    freopen("2020.in", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    while (cin >> n) {
        if (n == 0) break;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        sort(a, a + n, cmp);
        for (int i = 0; i < n; ++i) {
            if (i == 0) cout << a[i];
            else cout << " " << a[i];
        }
        cout << endl;
    }
    return 0;
}
