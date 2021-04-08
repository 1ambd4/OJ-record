#include <iostream>
#include <cmath>
using namespace std;

int f(int n) {
    return n * n + n + 41;
}

bool check(int n) {
    int t = sqrt(n + 0.5);
    for (int i = 2; i <= t; ++i) {
        if (n % i == 0) return true;
    }
    return false;
}

int main(void) {
#ifdef LOCAL
    freopen("2012.in", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    int x, y;
    bool flag;
    while (cin >> x >> y) {
        if (x == 0 && y == 0) break;
        flag = true;
        for (int i = x; i <= y; ++i) {
            if (check(f(i))) flag = false; 
        }
        if (flag) cout << "OK" << endl;
        else cout << "Sorry" << endl;
    }
    return 0;
}
