#include <iostream>
#include <cstring>
#include <sstream>
#include <ctype.h>
using namespace std;

int main(void) {
#ifdef LOCAL
    freopen("2026.in", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    while (getline(cin, s)) {
        bool f = true;
        stringstream ss(s);
        while (ss >> s) {
            s[0] = toupper(s[0]);
            if (f) cout << s, f = false;
            else cout << " " << s;
        }
        cout << endl;
    }
    return 0;
}
