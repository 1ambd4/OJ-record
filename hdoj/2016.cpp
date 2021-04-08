#include <iostream>
using namespace std;

constexpr int MAX = 100 + 10;
int s[MAX];

int main(void) {
#ifdef LOCAL
    freopen("2016.in", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, t;
    while (cin >> n) {
        if (n == 0) break;
        t = 0;
        for (int i = 0; i < n; ++i) {
            cin >> s[i];
            if (i == 0) t = 0;
            if (s[i] < s[t]) t = i;
        }
        swap(s[0], s[t]);
        for (int i = 0; i < n; ++i) {
            if (i == 0) cout << s[i];
            else cout << " " << s[i];
        }
        cout << endl;
    }
    return 0;
}
