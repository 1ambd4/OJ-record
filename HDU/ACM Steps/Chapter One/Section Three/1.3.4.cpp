#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

deque<int> dq;

int main(void) {
#ifdef LOCAL
    freopen("1.3.4.in", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, _t;
    while (cin >> n) {
        dq.clear();
        for (int i = 0; i < n; ++i) {
            cin >> _t;
            dq.push_back(_t);
        }
        sort(dq.begin(), dq.end(), less<int>());
        bool flag = true, _flag = true;
        while (!dq.empty()) {
            if (_flag) {
                _flag = false;
            }
            else {
                cout << " ";
            }
            if (flag) {
                cout << dq.back();
                dq.pop_back();
                flag = false;
            }
            else {
                cout << dq.front();
                dq.pop_front();
                flag = true;
            }
        }
        cout << endl;
    }
    return 0;
}
