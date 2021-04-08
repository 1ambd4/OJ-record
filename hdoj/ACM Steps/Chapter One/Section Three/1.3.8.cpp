#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

int n[4];
set<int> s[10];

int main(void) {
#ifdef LOCAL
    freopen("1.3.8.in", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    bool _flag = true;
    while(cin >> n[0] >> n[1] >> n[2] >> n[3]) {
        if (n[0] == 0 && n[1] == 0 && n[2] == 0 && n[3] == 0) break;
        for (int i = 0; i < 10; ++i) s[i].clear();
        do {
            int _n = n[0] * 1000 + n[1] * 100 + n[2] * 10 + n[3] * 1;
            s[_n/1000].insert(_n);
        } while (next_permutation(n, n + 4));
        if (_flag) {
            _flag = false;
        }
        else {
            cout << endl;
        }
        for (int i = 1; i < 10; ++i) if (!s[i].empty()){
            bool flag = true;
            for (auto& e : s[i]) {
                if (flag) {
                    flag = false;
                }
                else {
                    cout << " ";
                }
                cout << e;
            }
            cout << endl;
        }
    }
    return 0;
}