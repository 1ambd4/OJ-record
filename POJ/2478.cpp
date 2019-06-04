#include <iostream>
#include <cstring>
using namespace std;

typedef long long ll;

const ll MAX = 1e6 + 100;

ll phi[MAX], prime[MAX], sum[MAX];
bool check[MAX];
ll tot;

void phi_and_prime_table(ll n) {
    memset(check, 0, sizeof(check));
    phi[1] = 1; tot = 0;
    for (ll i = 2; i < n; ++i) {
        if (!check[i]) {
            prime[tot++] = i;
            phi[i] = i - 1;
        }
        for (ll j = 0; j < tot; ++j) {
            if (i * prime[j] > n) break;
            check[i * prime[j]] = true;
            if (i % prime[j] == 0) {
                phi[i * prime[j]] = phi[i] * prime[j];
                break;
            }
            else {
                phi[i * prime[j]] = phi[i] * (prime[j] - 1);
            }
        }
    }
}

void get_phi(ll n) {
    memset(phi, 0, sizeof(phi));
    phi[1] = 1;
    for (ll i = 2; i < n; ++i) {
        if (!phi[i]) {
            for (ll j = i; j < n; j += i) {
                if (!phi[j]) {
                    phi[j] = j;
                }
                phi[j] = phi[j] / i * (i - 1);
            }
        }
    }
}

void get_sum() {
    sum[1] = phi[1] = 0;
    for (int i = 2; i < MAX; ++i) sum[i] = sum[i-1] + phi[i];
}

int main(void) {
#ifdef LOCAL
    freopen("2478.in", "r", stdin);
#endif
    memset(sum, 0, sizeof(sum));
    phi_and_prime_table(MAX);
    get_sum();
    //get_phi(MAX);
    ll n;
    while (cin >> n) {
        if (n == 0) break;
        ll ans = sum[n];
        //ll ans = 0;
        //for (int i = 2; i <= n; ++i) ans += phi[i];
        cout << ans << endl;
    }

    return 0;
}