#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
#ifdef LOCAL
    freopen("2000.in", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    char s[5];
    while (cin >> s) {
        sort(s, s + 3);
        printf("%c %c %c\n", s[0], s[1], s[2]);
        //for (int i = 0; i < 3; ++i) cout << s[i] << ' '; cout << endl;
    }
    return 0;
}
