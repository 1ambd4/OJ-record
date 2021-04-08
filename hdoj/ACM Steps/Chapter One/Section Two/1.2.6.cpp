#include <iostream>
#include <cstdio>
using namespace std;

int main(void) {
#ifdef LOCAL
    freopen("1.2.6.in", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T, a, b;
    char op;
    cin >> T;
    while (T--) {
        cin >> op >> a >> b;
        int ans =  a + (op == '+') * b + (op == '-') * (-b) + (op == '*') * (a * b - a)  + (op == '/') * (a / b - a);
        if (op == '/' && a % b != 0) printf("%.2f\n", float(a)/b);
        else printf("%d\n", ans);
    }

    return 0;
}
