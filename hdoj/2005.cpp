#include <iostream>
using namespace std;

int n[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool is_leap_year(int y) {
    if ((y % 4 == 0 && y % 100 != 0) || y % 400 ==  0) return true;
    return false;
}

int main(void) {
#ifdef LOCAL
    freopen("2005.in", "r", stdin);
#endif
    int y, m, d;
    while (~scanf("%d/%d/%d", &y, &m, &d)) {
        int ans = 0;
        if (is_leap_year(y) && m > 3) ans++;
        for (m--; m > 0;) {
            ans += n[--m];
        }
        ans += d;
        cout << ans << endl;
    }
    
    return 0;
}
