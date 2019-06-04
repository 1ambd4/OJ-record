#include <iostream>
#include <stack>
using namespace std;

char a[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};

int main(void) {
#ifdef LOCAL
    freopen("2031.in", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, b, f;
    while (cin >> n >> b) {
        f = (n > 0 ? 1 : 0);
        if (!f) n = -n;
        stack<int> s;
        while (n != 0) {
            s.push((n % b));
            n /= b;
        }
        if (!f) cout << "-";
        while (!s.empty()) {
            cout << a[s.top()];
            s.pop();
        }
        cout << endl;
    }
    
    return 0;
}
