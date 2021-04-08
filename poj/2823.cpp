#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

const int MAX = 1e6 + 10;
int n, m, a[MAX];

int main(void) {
#ifdef LOCAL
    freopen("2823.in", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    while (cin >> n >> m) {
        deque<int> qmn, qmx;
        for (int i = 1; i <= n; ++i) cin >> a[i];
        for (int i = 1; i <= n; ++i) {
            if (qmn.empty()) qmn.push_back(i);
            else {
                while (!qmn.empty() && i-qmn.front()+1 > m) qmn.pop_front();
                while (!qmn.empty() && a[qmn.back()] > a[i]) qmn.pop_back();
                qmn.push_back(i);
            }
            if (i >= m) cout << a[qmn.front()] << " ";
        }
        cout << endl;
        for (int i = 1; i <= n; ++i) {
            if (qmx.empty()) qmx.push_back(i);
            else {
                while (!qmx.empty() && i-qmx.front()+1 > m) qmx.pop_front();
                while (!qmx.empty() && a[qmx.back()] < a[i]) qmx.pop_back();
                qmx.push_back(i);
            }
            if (i >= m) cout << a[qmx.front()] << " ";
        }        
        cout << endl;
    }
    return 0;
}
