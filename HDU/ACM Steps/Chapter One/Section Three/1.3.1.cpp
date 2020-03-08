#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

constexpr int MAX = 1e5 + 10;
struct Beans{
    int j, f;
    Beans() = default;
    Beans(int j, int f) : j(j), f(f) {}
}a[MAX];

bool cmp(Beans a, Beans b) {
    return a.j * 1.0 / a.f > b.j * 1.0 / b.f;
}

vector<Beans> v;

int main(void) {
#ifdef LOCAL
    freopen("1.3.1.in", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    int m, n, a, b;
    while (cin >> m >> n) {
        if (m == -1 and n == -1) break;
        v.clear();
        double ans = 0;
        for (int i = 0; i < n; ++i) {
            cin >> a >> b;
            v.push_back(Beans(a, b));
        }
        sort(v.begin(), v.end(), cmp);
        for (auto& e : v) {
            if (m == 0) break;
            if (m > e.f) {
                ans += e.j;
                m -= e.f;
            }
            else {
                ans += e.j * 1.0 / e.f * m;
                m -= m;
            }
        }
        printf("%.3f\n", ans);
    }
    return 0;
}