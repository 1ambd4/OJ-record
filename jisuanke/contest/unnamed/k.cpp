#include <iostream>
using namespace std;

constexpr int MAX = 1e5 + 10;
int num[MAX];

int f() {

}

int g() {

}

int w() {
    
}

int main(void) {
#ifdef LOCAL
    freopen("k.in", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t, n;
    cin >> t >> n;

    for (int i = 1; i <= n; ++i) {
        cin >> num[i];
    }

    int T, a, b, ans;
    cin >> T;
    while (T--) {
        cin >> a >> b;
        ans = b;
        for (int i = a; i < b; ++i) {
            ans |= i;
        }
        cout << ans << endl;
    }

    return 0;
}