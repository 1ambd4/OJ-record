#include <iostream>
#include <cstring>
using namespace std;

int main(void) {
#ifdef LOCAL
    freopen("2017.in", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;
        int len = s.length(), cnt = 0;
        for (int i = 0; i < len; ++i) {
            if (isdigit(s[i])) cnt++;
        }
        cout << cnt << endl;
    }
    return 0;
}
