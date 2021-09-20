#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 10000 + 10;

int a[MAX];

int main(void) {
#ifdef LOCAL
    freopen("2388.in", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    int n;
    while (cin >> n) {
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        sort(a, a + n);
        cout << a[n>>1] << endl;
    }
    return 0;
}
