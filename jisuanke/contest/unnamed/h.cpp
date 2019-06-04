#include <iostream>
using namespace std;

using ll = long long;
constexpr ll MAX = 1e8 + 10;
constexpr int MOD = 1000000007;
ll *num = new ll[MAX];
ll *_num = new ll[MAX];

int main(void) {
#ifdef LOCAL
    freopen("h.in", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll t;
    cin >> t;
    num[0] = 0;
    num[1] = 1;
    num[2] = 4;
    for (int i = 3; i <= t; ++i) {
        num[i] = 2 * ((num[i-1] % MOD + _num[i-1] % MOD) % MOD);
        _num[i] = (num[i-1] % MOD + _num[i-1] % MOD);
        //cout << num[i] << " " << _num[i] << endl;
    }
    //for (int i = 1)
    cout << num[t] << endl;
    return 0;
}