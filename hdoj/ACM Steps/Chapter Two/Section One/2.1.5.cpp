#include <iostream>
using namespace std;

constexpr int MAX = 1e6 + 10;
int lpf[MAX], cnt = 2, n;

int main(void) {
#ifdef LOCAL
    freopen("2.1.5.in", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    lpf[1] = 0; lpf[2] = 1;
    for (int i = 4; i < MAX; i += 2) {
        lpf[i] = lpf[2];\
    }
    for (int i = 3; i < MAX; i += 2) {
        if (lpf[i]) {
            continue;
        }
        lpf[i] = cnt++;
        for (int j = (i << 1); j < MAX; j += i) {
            lpf[j] = lpf[i];
        }
    }
    while (cin >> n) {
        cout << lpf[n] << endl;
    }

    return 0;
}