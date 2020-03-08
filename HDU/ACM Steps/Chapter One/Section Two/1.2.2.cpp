#include <iostream>
#include <cstdio>
using namespace std;

int main(void) {
#ifdef LOCAL
    freopen("1.2.2.in", "r", stdin);
#endif
#ifdef LOCAL
    freopen("log1.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    int a, b;
    while (~scanf("%x %x", &a, &b)) {
        printf("%d\n", a + b);
    }
    return 0;
}