#include <iostream>
using namespace std;

int main(void) {
#ifdef LOCAL
    freopen("1.1.2.in", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T, a, b;
    cin >> T;
    while (T--) {
        cin >> a >> b;
        cout << a + b << endl;
    }
    return 0;
}
