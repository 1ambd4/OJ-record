#include <iostream>
using namespace std;

constexpr int N = 30 + 5;
int dp[N];

int main(void) {
#ifdef LOCAL
    freopen("2013.in", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    dp[1] = 1;
    for (int i = 2; i < N; ++i) dp[i] = (dp[i-1] + 1) * 2;
    while (cin >> n) {
        cout << dp[n] << endl;
    }
    return 0;
}
