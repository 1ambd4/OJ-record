#include <iostream>
using namespace std;

int main(void) {
#ifdef LOCAL
    freopen("2010.in", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, cnt;
    while (cin >> n >> m) {
        cnt = 0;
        for (int i = n; i <= m; ++i) {
            if (i == ((i/100) * (i/100) * (i/100) + (i/10%10) * (i/10%10) * (i/10%10) + (i % 10) * (i % 10) * (i % 10))) {
                cnt++;
                if (cnt == 1) cout << i;
                else cout << " " << i;
            }
        }
        if (cnt == 0) cout << "no" << endl;
        else cout << endl;
    }
    
    return 0;
}
