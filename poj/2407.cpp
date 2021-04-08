#include <iostream>
#include <cmath>
using namespace std;

typedef long long ll;

ll euler_phi(ll n) {
    ll m = sqrt(n + 0.5);
    ll ans = n;
    for (ll i= 2; i <= m; ++i) if (n % i == 0) {
        ans -= ans / i;
        while (n % i == 0) {
            n /= i;
        }
    }
    if (n > 1) ans -=  ans / n;
    return ans;
}

int main(void) {
#ifdef LOCAL
    freopen("2407.in", "r", stdin);
#endif
    ll n;
    while (cin >> n) {
        if (n == 0) break;
        cout << euler_phi(n) << endl;
    }

    return 0;
}