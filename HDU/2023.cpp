#include <iostream>
#include <cstring>
using namespace std;

int a[55][10];

int main(void) {
#ifdef LOCAL
    freopen("2023.in", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, cnt;
    while (cin >> n >> m) {
        cnt = n;
        memset(a, 0, sizeof(a));
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                cin >> a[i][j];
                a[i][0] += a[i][j];
                a[0][j] += a[i][j];
            }
        }
        for (int i = 1; i <= n; ++i) {
            if (i == 1) printf("%.2f", a[i][0] / (double)m);
            else printf(" %.2f", a[i][0] / (double)m);
            for (int j = 1; j <= m;  ++j) {
                if (a[i][j] < a[0][j] / (double)m) {
                    cnt--;
                    break;
                }
            }
        }
        printf("\n");
        for (int i = 1; i <= m; ++i) {
            if (i == 1) printf("%.2f", a[0][i] / (double)n);
            else printf(" %.2f", a[0][i] / (double)n);
        }
        printf("\n");
        printf("%d\n\n", cnt);
    }
    return 0;
}
