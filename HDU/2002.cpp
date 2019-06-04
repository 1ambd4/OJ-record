#include <iostream>
using namespace std;

constexpr double PI = 3.1415927;

int main(void) {
#ifdef LOCAL
    freopen("2002.in", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    double r;
    while (cin >> r) {
        printf("%.3f\n", 4 * PI * r * r * r / 3);
    }
    return 0;
}
