#include <iostream>
#include <cstdio>
using namespace std;

int main(void) {
#ifdef LOCAL
    freopen("1004.in", "r", stdin);
#endif
    double penny, ans = 0;
    for (int i = 0; i < 12; ++i) {
        cin >> penny;
        ans += penny;
    }
    printf("$%.2f\n", ans/12);
    return 0;
}
