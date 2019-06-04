#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long ll;
const int MAX = 1000 + 10;

ll p[65], cnt, ans;
// vector<pair<ll, ll> > v{MAX};    // C++11/14
vector<pair<ll, ll> > v(MAX, make_pair(0,0));   // C++99

bool cmp(pair<ll, ll> a, pair<ll, ll> b) {
    return a.second > b.second;
}

void gauss(int n) {
    ans = 0;
    memset(p, 0, sizeof(p));
    for (int i = 0; i < n; ++i) {
        for (int j = 63; j >= 0; --j) if ((v[i].first>>j) & 1) {
            if (p[j]) {
                v[i].first ^= p[j];
            }
            else {
                p[j] = v[i].first;
                ans += v[i].second;
                break;
            }
        }
    }
}

int main(void) {
#ifdef LOCAL
    freopen("2460.in", "r", stdin);
#endif
    int n; ll _ta, _tb;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> _ta >> _tb;
        v[i].first = _ta;
        v[i].second = _tb;
    }
    sort(v.begin(), v.begin()+n, cmp);
    gauss(n);
    cout << ans << endl;
    //for (int i = 0; i < n; ++i) cout << v[i].first << " " << v[i].second << endl;

    return 0;
}
