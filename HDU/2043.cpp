#include <iostream>
#include <cstring>
using namespace std;

int main(void) {
#ifdef LOCAL
    freopen("2043.in", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    string s;
    cin >> T;
    while (T--) {
        int n[4];
        memset(n, 0, sizeof(n));
        cin >> s;
        int len = s.length();
        if (len > 16 || len < 8) {
            cout << "NO" << endl;
            continue;
        }
        for (int i = 0; i < len; ++i) {
            if (s[i] >= '0' && s[i] <= '9') n[0]++;
            else if (s[i] >= 'a' && s[i] <= 'z') n[1]++;
            else if (s[i] >= 'A' && s[i] <= 'Z') n[2]++;
            else n[3]++;
        }
        int cnt = 0;
        for (int i = 0; i < 4; ++i) {
            if (n[i] > 0) cnt++;
        }
        if (cnt >= 3) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}
