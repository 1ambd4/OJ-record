#include <iostream>
using namespace std;

#include <vector>
#include <algorithm>

const int MAXN = 100 + 10;
const int MAXM = MAXN * (MAXN - 1) >> 1;

class Kruskal {
private:
    struct UdEdge {
        int s, t, w;
        UdEdge() = default;
        UdEdge(int s, int t, int w) : s(s), t(t), w(w) {} 
    };
    int n, m;   // n个点，m条边
    UdEdge pool[MAXM];
    UdEdge* e[MAXM];
    int pre[MAXN];
    int find(int p) {
        return pre[p] == p ? p : pre[p] = find(pre[p]);
    }
public:
    static bool cmp(const UdEdge* a, const UdEdge* b) {
        return a->w < b->w;
    }
    void clear(int n) {
        this->n = n;
        this->m = 0;
    }
    void add_edge(int s, int t, int w) {
        pool[m] = UdEdge(s, t, w);
        e[m] = &pool[m];
        ++m;
    }
    int run() {
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            pre[i] = i;
        }
        sort(e, e + m, cmp);
        for (int i = 0; i < m; ++i) {
            UdEdge* _e = e[i];
            int x = find(_e->s);
            int y = find(_e->t);
            if (x != y) {
                pre[y] = x;
                ans += _e->w;
            }
        }
        return ans;
    }
};

int main(void) {
#ifdef LOCAL
    freopen("1233.in", "r", stdin);
#endif
    int m, n, s, t, w;
    Kruskal solve;
    while (cin >> n) {
        if (n == 0) break;
        m = n * (n - 1)>>1;
        solve.clear(n + 1);
        for (int i = 0; i < m; ++i) {
            cin >> s >> t >> w;
            solve.add_edge(s, t, w);
        }
        cout << solve.run() << endl;
    }
    return 0;
}