#include <iostream>
#include <cstring>
using namespace std;

int main(void) {
#ifdef LOCAL
    freopen("1.2.5.in", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    while (getline(cin, s, '\n')) {
        if (s == "#") break;
        int len = s.length();
        for (int i = 0; i < len; ++i) {
            if (s[i] == ' ' | s[i] == '!' || s[i] == '$' || s[i] == '%' || s[i] == '(' || s[i] == ')') cout << "%" << (int)s[i] - 12;
            else if (s[i] == '*') cout << "%2a";
            else cout << s[i];
        }
        cout << endl;
    }
    
    return 0;
}
