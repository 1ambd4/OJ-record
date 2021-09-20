#include <iostream>
using namespace std;

const int INF = 0x3f3f3f3f;
const int MAX = 100 + 10;
int d[MAX][MAX];
int n, m;

void init() {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            d[i][j] = INF;
        }
    }
}

void floyd() {
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
}

int main(void) {
#ifdef LOCAL
    freopen("3660.in", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    while(cin >> n >> m) {
        if (n == 0 || m == 0) break;
        init();
        int x, y, ans = 0;
        while (m--) {
            cin >> x >> y;
            d[x-1][y-1] = 1;
        }
        floyd();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == j) continue;
                if (d[i][j] == INF && d[j][i] == INF) {
                    ans++;
                    break;
                }
            }
        }
        cout << n - ans << endl;
    }
    return 0;
}