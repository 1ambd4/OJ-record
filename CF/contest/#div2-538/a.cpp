#include <iostream>
using namespace std;

int main(void) {
#ifdef LOCAL
freopen("a.in", "r", stdin);
#endif
    int a, b, c;
    int x, y, z;
    cin >> a >> b >> c;
    cin >> x >> y >> z;
    if (a > x) {
        cout << "NO\n" << endl;
        return 0;
    }
    if (a + b > x + y) {
        cout << "NO\n" << endl;
        return 0;
    }
    if (a + b + c > x + y + z) {
        cout << "NO\n" << endl;
        return 0;
    }
    cout << "YES\n" << endl;
    return 0;
}