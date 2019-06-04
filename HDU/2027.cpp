#include <iostream>
#include <cstring>
#include <sstream>
#include <algorithm>
#include <cstdio>
#include <map>
using namespace std;

int main(void) {
#ifdef LOCAL
    freopen("2027.in", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    string s;
    map<char, int> m;
    getline(cin, s, '\n');
    stringstream ss(s);
    ss >> T;
    while (T--) {
        fflush(stdin);
        m.clear();
        m.insert(make_pair('a', 0));
        m.insert(make_pair('e', 0));
        m.insert(make_pair('i', 0));
        m.insert(make_pair('o', 0));
        m.insert(make_pair('u', 0));
        getline(cin, s, '\n');
        stringstream ss(s);
        while (ss >> s) {
            for (int i = 0; i < s.length(); ++i) {
                if (s[i]== 'a' || s[i]== 'e' || s[i]== 'i' || s[i]== 'o' || s[i]== 'u') m[s[i]]++;
            }
        }
        for (auto it = m.begin(); it != m.end(); it++) {
            cout << (*it).first << ":" << (*it).second << endl;
        }
        if (T) cout << endl;
    }
    return 0;
}
