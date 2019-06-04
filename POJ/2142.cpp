#include <iostream>
using namespace std;

typedef long long ll;

ll extend_eulid(ll a, ll b, ll&x, ll& y) {
    if (0 == b) {
        x = 1; y = 0;
        return a;
    }
    ll d = extend_eulid(b, a % b, y, x);
    y -= a / b * x;
    return d;
}

int main(void) {
    ll a, b, d, x, y, g;
    while (cin >> a >> b >> d) {
        if (!a && !b && !d) break;
        g = extend_eulid(a, b, x, y);
        ll s = d / g;
    }

    return 0;
}