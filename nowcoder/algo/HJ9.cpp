#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

int main()
{
    unsigned int n;
    bool v[10] {false};
    while (cin >> n) {
        unsigned int res = 0;
        memset(v, 0, sizeof(v));
        while (n != 0) {
            int c = n % 10;
            n /= 10;
            if (v[c]) continue;
            res = res * 10 + c;
            v[c] = true;
        }
        cout << res << endl;
    }
    return 0;
}
