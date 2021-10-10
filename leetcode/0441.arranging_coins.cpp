#include <iostream>
#include <cmath>

using namespace std;

int arrange_conins(int n)
{
    long l = 1, r = n;
    while (l < r) {
        long m = (l + r + 1) >> 1;
        if (m*(m+1) / 2 <= n) {
            l = m;
        } else {
            r = m - 1;
        }
    }
    return r;
}

int main()
{
    cout << arrange_conins(1) << endl;
    cout << arrange_conins(3) << endl;
    cout << arrange_conins(5) << endl;
    cout << arrange_conins(8) << endl;
    return 0;
}
