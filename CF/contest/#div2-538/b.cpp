#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

const int MAX = 2e5 + 10;
int a[MAX];
vector<int> v;
vector<int>::iterator it;

int main(void) {
#ifdef LOCAL
freopen("b.in", "r", stdin);
#endif
    int n, m, k, ans = 0;
    scanf("%d%d%d", &n, &m, &k);
    //cin >> n >> m >> k;
    for (int i = 0; i < n; ++i) {
        //cin >> a[i];
        scanf("%d", &a[i]);
        v.push_back(a[i]);
    }
    //sort(v.begin(), v.end(), less<int>());
    sort(v.begin(), v.end(), greater<int>());
    int t = n - m * k;
    while (t--) v.pop_back();
    //for_each(it + m * k, v.end(), );
    //cout << accumulate(v.begin(), v.end(), 0) << endl;
    printf("%d\n", accumulate(v.begin(), v.end(), 0));
    int _t = 0, _cnt = 0, _sum = 0;
    for (int i = 0; i < n; ++i) {
        //it = find(v.begin(), v.end(), a[i]);
        it = find(v.begin(), v.end(), a[i]);
        if (it != v.end()) {
            //for (int &e: v) cout << e << " "; cout << endl;
            _t++;
            //cout << *it << endl;
            v.erase(it);
        }
        if (_t == m) {
            //cout <<  _t << endl;
            //cout << i + 1 << " ";
            printf("%d ", i + 1);
            _t = 0;
            _sum++;
        }
        if (_sum == k - 1) break;
    }
    printf("\n");
    //for (int &it: v) cout << it << " "; cout << endl;
    //cout << ans << endl;

    return 0;
}