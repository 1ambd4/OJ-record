#include <iostream>
using namespace std;

int main(void) {
#ifdef LOCAL
    freopen("1006.in", "r", stdin);
#endif
    int p, e, i, d, t = 1;
    while (cin >> p >> e >> i >> d) {
        if (p == -1 && e ==  -1 && i == -1 && d == -1) break;
        int lcm = 23 * 28 * 33;
        int n = (28 * 33 * 6 * p + 23 * 33 * 19 * e + 28 * 23 * 2 * i -d + lcm) % lcm;
        if (n == 0) n = lcm;
        cout << "Case " << t++ << ": the next triple peak occurs in " << n << " days." << endl;
    }

    return 0;
}
