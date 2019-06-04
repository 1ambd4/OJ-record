#include <iostream>
using namespace std;

char g[4]{'D', 'C', 'B', 'A'};

int main(void) {
#ifdef LOCAL
    freopen("2004.in", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    int a;
    while (cin >> a) {
        if (a > 100 || a < 0) {
            cout << "Score is error!" << endl;
            continue;
        }
        if (a < 60) {
            cout << "E" << endl;
            continue;
        }
        cout << g[(a - 61) / 10] << endl;
    }
    return 0;
}
