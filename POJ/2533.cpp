#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 1e5  +10;
int arr[MAX], num[MAX], n;

template <class Cmp>
int LIS(Cmp cmp) {
    int m = 0;
    for (int i = 0; i < n; ++i) {
        int pos = lower_bound(num, num + m, arr[i], cmp) - num;
        num[pos] = arr[i];
        m += pos == m;
    }
    return m;
}

int main(void) {
#ifdef LOCAL
  freopen("2533.in", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    while (cin >> n) {
        for (int i = 0; i < n; ++i) cin >> arr[i];
        cout << LIS(less<int>()) << endl;
    }
    return 0;
}