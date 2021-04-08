#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

constexpr int MAX = 1000 + 5;
struct RICE {
    int p, h;
    RICE() = default;
    RICE(int p, int h) : p(p), h(h) {}
};

bool cmp(RICE& a, RICE& b) {
    return a.p < b.p;
}

vector<RICE> v;

int main(void) {
#ifdef LOCAL
    freopen("1.3.7.in", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T, m, _p, _h;
    double n;
    cin >> T;
    while (T--) {
        double ans = 0;
        v.clear();
        cin >> n >> m;
        for (int i = 0; i < m; ++i) {
            cin >> _p >> _h;
            v.push_back(RICE(_p, _h));
        }
        sort(v.begin(), v.end(), cmp);
        for (auto& e : v) {
            if (n == 0) break;
            if (n > e.p  * e.h) {
                ans += e.h;
                n -= e.p * e.h;
            }
            else {
                ans += n / e.p;
                n -= n / e.p * e.p;
            }
        }
        printf("%.2f\n", ans);
    }
    return 0;
}
