#include <iostream>
using namespace std;

constexpr int MAX = 1e5 + 10;


int main(void) {
#ifdef LOCAL
    freopen("i.in", "w", stdout);
#endif
    cout << MAX << endl;
    for (int i = 0; i < MAX; ++i) {
        cout << 500000 << " ";
    }

    return 0;
}