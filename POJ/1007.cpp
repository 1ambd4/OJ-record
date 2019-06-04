#include <iostream>
#include <algorithm>
using namespace std;

struct S {
    char s[55];
    int c;
}ss[105];

bool cmp(struct S a, struct S b) {
    return a.c < b.c;
}

int main(void) {
#ifdef LOCAL
    freopen("1007.in", "r", stdin);
#endif
    int n, m;
    while (cin >> n >> m) {
        for (int i = 0; i < m; ++i) {
            cin >> ss[i].s;
            ss[i].c = 0;
            for (int j = 0; j < n; ++j) {
                for (int k = j; k < n; ++k) {
                    if (ss[i].s[j] > ss[i].s[k]) {
                        ss[i].c++;
                    }
                }
            }
        }
        sort(ss, ss + m, cmp);
        for (int i = 0; i < m; ++i) cout << ss[i].s << endl;
    }
    return 0;
}
