#include <iostream>
using namespace std;

int main(void) {
#ifdef LOCAL
    freopen("2007.in", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    int a, b, sa, sb;
    while (cin >> a >> b) {
        if (a > b) swap(a, b);
        sa = sb = 0;
        for (int i = a; i <= b; ++i) {
            if (i & 1) sb += i * i * i;
            else sa += i * i;
        }
        cout << sa << " " << sb << endl;
    }
    return 0;
}