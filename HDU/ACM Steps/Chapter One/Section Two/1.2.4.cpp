#include <iostream>
using namespace std;

int main(void) {
#ifdef LOCAL
    freopen("1.2.4.in", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while(T--) {
        int y, n;
        cin >> y >> n;
        for ( ; n > 0; ) {
            if ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0) n--;
            y++;
        }
        cout << y - 1 << endl;
    }
    return 0;
}
