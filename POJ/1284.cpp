#include <iostream>
#include <cmath>
using namespace std;

typedef long long ll;

ll euler_phi(ll n) {
    ll m = sqrt(n + 0.5);
    ll ans = n;
    for (int i = 2; i <= m; ++i) if (n % i == 0) {
        ans -= ans / i;
        while (n % i == 0) {
            n /= i;
        }
    }
    if (n > 1) {
        ans -= ans / n;
    }
    return ans;
}

int main(void) {
#ifdef LOCAL
    freopen("1284.in", "r", stdin);
#endif
    ll n;
    while(cin >> n) {
        cout << euler_phi(n-1) << endl;
    }
    return 0;
}