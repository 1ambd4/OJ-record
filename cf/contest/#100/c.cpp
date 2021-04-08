#include <iostream>
#include <unordered_map>
#include <queue>
using namespace std;

struct NODE {
    int a, b, c;
};

const int MAX = 1e5 + 7;
unordered_map<int, int> mp;
priority_queue<pair<int, int> > q;
vector<NODE> ans;
int n;

int main(void) {
#ifdef LOCAL
    freopen("c.in", "r", stdin);
#endif
    int t;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> t;
        mp[t]++;
    }
    for (auto it = mp.begin(); it != mp.end(); ++it) {
        q.push(pair<int, int>(it->second, it->first));
    }
    if (q.size() < 3) return 0*printf("0\n");
    while (q.size() >= 3) {
        pair<int, int> a, b, c;
        a = q.top(); q.pop();
        b = q.top(); q.pop();
        c = q.top(); q.pop();
        ans.push_back({a.second, b.second, c.second});
        if (a.first > 1) q.push(make_pair(a.first - 1, a.second));
        if (b.first > 1) q.push(make_pair(b.first - 1, b.second));
        if (c.first > 1) q.push(make_pair(c.first - 1, c.second));
    }
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); ++i) {
        if (ans[i].a < ans[i].b) swap(ans[i].a, ans[i].b);
        if (ans[i].a < ans[i].c) swap(ans[i].a, ans[i].c);
        if (ans[i].b < ans[i].c) swap(ans[i].b, ans[i].c);
        cout << ans[i].a << " " << ans[i].b << " " << ans[i].c << endl;
    }
    return 0;
}
