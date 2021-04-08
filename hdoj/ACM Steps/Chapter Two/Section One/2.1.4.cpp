#include <iostream>
using namespace std;

int gcd(int a, int b) {
    while (b != 0) {
        int t = a % b;
        a = b;
        b = t;
    }
    return a;
}

int main(void) {
#ifdef LOCAL
    freopen("2.1.4.in", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    int a, b;
    while (cin >> a >> b) {
        cout << a + b - gcd(a, b) << endl;
    }
    return 0;
}
