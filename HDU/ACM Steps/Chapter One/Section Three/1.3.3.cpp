#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

constexpr int MAX = 50 + 5;
struct S{
    S() = default;
    S(int a, int b): a(a), b(b) {}
    int a, b;
}s[MAX];

bool cmp(S a, S b) {
    return a.a < b.a;
}

vector<S> v;

int main(void) {
#ifdef LOCAL
    freopen("1.3.3.in", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T, n, a, b;
    cin >> T;
    while (T--) {
        v.clear();
        cin >> n;
        while (n--) {
            cin >> a >> b;
            v.push_back(S(a, b));
        }
        sort(v.begin(), v.end(), cmp);
        for (auto &e : v) {
            for (int i = 0; i < e.b; ++i) {
                cout << ">+";
                for (int i = 0; i < e.a - 2; ++i) {
                    cout << "-";
                }
                cout << "+>" << endl;
            }
            cout << endl;
        }       
    }
    return 0;
}