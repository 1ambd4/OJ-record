#include <iostream>
#include <sstream>
#include <cstring>
using namespace std;

int main(void) {
#ifdef LOCAL
    freopen("2030.in", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T, cnt;
    string s;
    getline(cin, s, '\n');
    stringstream ss(s);
    ss >> T;
    while (T--) {
        cnt = 0;
        getline(cin, s, '\n');
        stringstream ss(s);
        while (ss >> s) {
            for (int i = 0; i < s.length(); ++i) if ((int)s[i] < 0) {
                cnt++;
            }
        }
        printf("%d\n", cnt/2);
    }
    return 0;
}
