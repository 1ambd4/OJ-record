#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 15000;
int v[N], w[N];
int f[N];
int cnt = 0;

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);

    for (int i = 1; i <= n; ++i) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        int k = 1;
        while (c >= k) {
            c -= k;
            ++cnt;
            v[cnt] = k * a;
            w[cnt] = k * b;
            k *= 2;
        }
        if (c > 0) {
            ++cnt;
            v[cnt] = c * a;
            w[cnt] = c * b;
        }
    }

    for (int i = 1; i <= cnt; ++i) {
        for (int j = m; j >= v[i]; --j) {
            f[j] = max(f[j], f[j-v[i]] + w[i]);
        }
    }

    cout << f[m] << endl;

    return 0;
}
