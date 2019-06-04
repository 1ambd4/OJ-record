#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

struct _a{
    int v, s;
}a[105];

bool cmp(_a a, _a b) {
    return a.v < b.v;
}

int main(void) {
#ifdef LOCAL
    freopen("2034.in", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, b;
    while (cin >> n >> m) {
        if (n == 0 && m == 0) break;
        set<int> s;
        bool flag = false;
        for (int i = 0; i < n; ++i) {
            cin >> a[i].v;
            a[i].s = true;
        }
        for (int i = 0; i < m; ++i) {
            cin >> b;
            s.insert(b);
        }
        for (auto it = s.begin(); it != s.end(); ++it) {
            for (int i = 0; i < n; ++i) {
                if (a[i].v == *it) a[i].s = false;
            }
        }
        sort(a, a + n, cmp);
        for (int i = 0; i < n; ++i) {
            if (a[i].s) {
                cout << a[i].v << " ";
                flag = true;
            }
        }
        if (!flag) cout << "NULL";
        cout << endl;
    }
    
    return 0;
}
