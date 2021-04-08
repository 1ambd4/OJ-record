#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

//const int MAX = 2e5 + 10;
//int a[MAX];
//vector<int> v;
//vector<int>::iterator it;

typedef pair<int, int> pii;
typedef long long ll;

int main(void) {
#ifdef LOCAL
freopen("b.in", "r", stdin);
#endif
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);

    vector<pii> v(n);
    vector<int> ind(m * k);
    //cin >> n >> m >> k;
    for (int i = 0; i < n; ++i) {
        //cin >> a[i];
        scanf("%d", &v[i].first);
        v[i].second = i;
    }
    //sort(v.begin(), v.end(), less<int>());
    sort(v.begin(), v.end(), greater<pii>());
    //int t = n - m * k;
    //while (t--) v.pop_back();
    //for_each(it + m * k, v.end(), );
    //cout << accumulate(v.begin(), v.end(), 0) << endl;
    //printf("%d\n", accumulate(v.begin(), v.end(), 0));
    ll sum = 0;
    for (int i = 0; i < m * k; ++i) {
        sum += v[i].first;
        ind[i] = v[i].second;
        //cout << v[i].first << " " << v[i].second << endl;
    }

    /*
    or (int i = 0; i < n; ++i) {
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
    }*/
    sort(ind.begin(), ind.end());

    printf("%lld\n", sum);
    for (int i = 0; i < k - 1; ++i) printf("%d ", ind[(i + 1) * m - 1] + 1);
    printf("\n");
    //for (int &it: v) cout << it << " "; cout << endl;
    //cout << ans << endl;

    return 0;
}