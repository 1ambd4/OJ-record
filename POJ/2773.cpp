#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;

typedef long long ll;

const int MAX =  1e6 + 10;
ll euler[MAX];

void get_euler() {
    memset(euler, 0, sizeof(euler));
    euler[1] = 1;
    for (int i = 2; i <= MAX; ++i) {
        if (!euler[i]) {
            for (int j = i; j <= MAX; j += i) {
                if (!euler[j]) {
                    euler[j] = j;
                }
                euler[j] = euler[j] / i * (i - 1);
            }
        }
    }
}

ll euler_phi(ll n) {
    ll m = sqrt(n + 0.5);
    ll ans = n;
    for (ll i = 2; i <= m; ++i) if (n % i == 0) {
        ans -= n / i;
        while (n % i == 0) {
            n /= i;
        }
    }
    if (n > 1) ans -= ans / n;
    return ans;
}

ll gcd(ll a, ll b) {
    ll t;
    while (b != 0) {
        t = a % b;
        a = b;
        b = t;
    }
    return a;
}

int main(void) {
#ifdef LOCAL
    freopen("2773.in", "r", stdin);
#endif
    ll n, k;
    get_euler();
    while (cin >> n >> k) {
        /*ll phi = euler_phi(n);
        ll t = k / phi;
        ll p = k % phi;
        if (p == 0) {
            t--;
            p = phi;
        }
        ll i;
        for (i = 1; i <= n; ++i) {
            if (gcd(n, i) == 1) p--;
            if (p == 0) break;
        }
        cout << (long long)t * n + i << endl; 
        */

        ll t = k / euler[n];
        ll p = k % euler[n];
        if (p == 0) {
            t--;
            p = euler[n];
        }
        ll i;
        for (i = 1; i <= n; ++i) {
            if (gcd(i, n) == 1) p--;
            if (p == 0) break;
        }
        cout << (ll)t * n + i << endl;
    }

    return 0;
}