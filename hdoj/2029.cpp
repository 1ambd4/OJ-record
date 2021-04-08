#include <iostream>
#include <cstring>
using namespace std;

int main(void) {
#ifdef LOCAL
    freopen("2029.in", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    string s;
    bool flag;
    cin >> n;
    while (n--) {
        flag = true;
        cin >> s;
        int len = s.length();
        for (int i = 0; i < len>>2; ++i) {
            if (s[i] != s[len-1-i]) flag = false;
        }
        if (flag) cout << "yes" << endl;
        else cout << "no" << endl;
    }
    return 0;
}
