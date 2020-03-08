#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

vector<int> v;
vector<int>::iterator it;

int main(void) {
#ifdef LOCAL
    freopen("2.1.7.in", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int T, n;
    cin >> T;
    while (T--) {
        cin >> n;
        v.clear();
        int cnt = 1;
        int t = sqrt(n + 0.5);
        for (int i = 2; i <= t; ++i) {
            if (n % i == 0) {
                v.push_back(i);
                v.push_back(n/i);
            }
        }
        sort(v.begin(), v.end(), less<int>());

        int len = v.size();
        for (int i = 2; i < n; i++) {
            for (it = v.begin(); it != v.end(); ++it) {
                if (i % (*it) == 0) {
                    cnt++;
                    break;
                }
            }
        }

        cout << n - cnt << endl;
    }
    return 0;
}
