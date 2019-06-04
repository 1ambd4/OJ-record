#include <iostream>
#include <cstring>
#include <cstdio>
#include <sstream>
using namespace std;

int main(void) {
#ifdef LOCAL
    freopen("2024.in", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    string s;
    getline(cin, s);
    stringstream ss(s);
    ss >> T;
    while (T--) {
        int cnt = 0;
        bool flag = true;
        getline(cin, s);
        stringstream ss(s);
        while (ss >> s) {
            cnt++;
            if (cnt > 1) flag = false;
            if (!(cnt == 1 && (isalpha(s[0]) || s[0] == '_'))) flag = false;
            for (int i = 1; i < s.length(); ++i) if (!(isalnum(s[i]) || s[i] == '_')) {
                flag = false;
            }
        }
        if (flag) cout << "yes" << endl;
        else cout << "no" << endl;
    }
    return 0;
}
