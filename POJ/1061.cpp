#include <iostream>
#include <ctime>
using namespace std;

inline int extend_eulid(int a, int b, int& x, int& y) {
    int d;
    if (0 == b) {
        x = 1;
        y = 0;
        return a;
    }
    d = extend_eulid(b, a % b, y, x);
    y -= a / b * x;
    return d;
}

int main(void) {
#ifdef LOCAL
    freopen("1061.in", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    int n, a;
    while ((n=scanf("%d", &a)) + 1) ;
    cout << n  << " " << a << endl;
    return 0;
}
