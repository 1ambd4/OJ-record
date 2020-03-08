#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

constexpr int MAX = 1e5 + 10;

struct STU {
    string id;
    int score;
    STU() = default;
    STU(string id, int score): id(id), score(score) {}
}stu[MAX];

bool cmp(STU a, STU b) {
    if (a.score != b.score) {
        return a.score > b.score;
    }
    else {
        return a.id < b.id;
    }
}

int main(void) {
#ifdef LOCAL
    freopen("1.3.2.in", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    vector<STU> v;
    vector<int> score;
    int n, m, g, t, _t, _s, c;
    string s;
    while (cin >> n) {
        if (n == 0) break;
        c = 0;
        v.clear();
        score.clear();
        cin >> m >> g;
        for (int i = 0; i < m; ++i) {
            cin >> _t;
            score.push_back(_t);
        }
        for (int i = 0; i < n; ++i) {
            _s = 0;
            cin >> s >> t;
            for (int i = 0; i < t; ++i) {
                cin >> _t;
                _s += score[_t-1];
            }
            if (_s >= g) {
                v.push_back(STU(s, _s));
                c++;
            }
        }
        sort(v.begin(), v.end(), cmp);
        cout << c << endl;
        for (auto &e : v) {
            cout << e.id << " " << e.score << endl;
        }
    }
    return 0;
}