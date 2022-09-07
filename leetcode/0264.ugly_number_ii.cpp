#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int ugly_number(int n)
{
    vector<int> u(n+1);
    int a = 2, b = 3, c = 5;
    int aa = 1, bb = 1, cc = 1;
    int pa = 1, pb = 1, pc = 1;
    int cnt = 1, cur = -1;

    while (cnt <= n) {
        cur = min(aa, min(bb, cc));
        u[cnt++] = cur;
        if (cur == aa) aa = a * u[pa++];
        if (cur == bb) bb = b * u[pb++];
        if (cur == cc) cc = c * u[pc++];
    }

    return u[n];
}

int main()
{
    cout << ugly_number(10) << endl;
    cout << ugly_number(1) << endl;
    cout << ugly_number(11) << endl;
    return 0;
}
