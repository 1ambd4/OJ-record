#include <iostream>
using namespace std;

int main(void) {
#ifdef LOCAL
    freopen("1000.in", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    int a, b;
    while (cin >> a >> b) {
        cout << a + b << endl;
    }
    return 0;
}
