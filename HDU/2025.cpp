#include <iostream>
using namespace std;

int main(void) {
#ifdef LOCAL
    freopen("2025.in", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    while (cin >> s) {
        int t = 0;
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] > s[t]) t = i;
        }
        for (int i = 0; i < s.length(); ++i) {
            cout << s[i];
            if (s[i] == s[t]) cout << "(max)";
        }
        cout << endl;
    }
    
    return 0;
}
