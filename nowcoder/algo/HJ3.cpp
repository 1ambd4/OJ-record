#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

int main()
{
    int n, t;
    set<int, less<int>> s;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> t;
        s.insert(t);
    }

    for (const auto e : s) cout << e << endl;

    return 0;
}
