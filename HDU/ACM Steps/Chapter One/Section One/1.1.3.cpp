#include <iostream>
using namespace std;

int main(void) {
#ifdef LOCAL
    freopen("1.1.3.in", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    int a, b;
    while (cin >> a >> b) {
        if (a == 0 && b == 0) break;
        cout << a + b << endl;
    }
    return 0;
}
