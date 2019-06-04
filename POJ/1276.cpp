#include <iostream>
#include <cstring>
using namespace std;

const int MAX = 1e5 + 10;
int n[MAX],c[MAX], v[MAX], dp[MAX], m;

bool zero_one_pack(int cost, int value) {
    for (int i = m; i >= cost; --i) {
        dp[i] = max(dp[i], dp[i - cost] + value);
    }
    return true;
}

bool complete_pack(int cost, int value) {
    for (int i = cost; i <= m; ++i) {
        dp[i] = max(dp[i], dp[i - cost] + value);
    }
    return true;
}

bool multiple_pack(int cost, int value, int cnt) {
    if (cost * cnt >= m) complete_pack(cost, value);
    else {
        for (int k = 1; k < cnt; k <<= 1) {
            zero_one_pack(k * cost, k * value);
            cnt -= k;
        }
        zero_one_pack(cnt * cost, cnt * value);
    }
    return true;
}

int main(void) {
#ifdef LOCAL
  freopen("1276.in", "r", stdin);
#endif
    int t;
    while (cin >> m >> t) {
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= t; ++i) {
            cin >> n[i] >> c[i];
            v[i] = c[i];
        }

        for (int i = 1; i <= t; ++i) {
            multiple_pack(c[i], v[i], n[i]);
        }
        cout << dp[m] << endl;
    }
    return 0;
}