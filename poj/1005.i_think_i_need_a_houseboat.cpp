#include <iostream>
#include <cmath>
using namespace std;

const double PI = acos(-1);

int main(void) {
#ifdef LOCAL
    freopen("1005.in", "r", stdin);
#endif
    int T;
    double x, y;
    cin >> T;
    for (int i = 1; i <= T; ++i) {
        cin >> x >> y;
        cout << "Property " << i << ": This property will begin eroding in year " << floor(PI * (pow(x, 2) + pow(y, 2)) / 100) + 1 << "." << endl;
    }
    cout << "END OF OUTPUT." << endl;
    return 0;
}
