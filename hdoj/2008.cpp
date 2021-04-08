#include <iostream>
using namespace std;

int main(void) {
#ifdef LOCAL
    freopen("2008.in", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, a, b, c;
    double x;
    while (cin >> n) {
        if (!n) break;
        a = b = c = 0;
        while (n--) {
            cin >> x;
            if (x > 0) c++;
            else if (x < 0) a++;
            else b++;
        }
        cout << a << " " << b << " " << c << endl;
    }
    
    return 0;
}
