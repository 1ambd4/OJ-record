#include <iostream>
#include <cmath>
using namespace std;

int main(void) {
#ifdef LOCAL
    freopen("2003.in", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    double a;
    while (cin >> a) {
        printf("%.2f\n", fabs(a));
    }
    return 0;
}
