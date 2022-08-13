#include <iostream>
#include <vector>

using namespace std;

int tribonacci(int n)
{
    if (n == 0) return 0;
    // if (n == 1 || n == 2) return 1;

    int t0 = 0, t1 = 1, t2 = 1, t3 = -1;

    for (int i = 3; i <= n; ++i) {
        t3 = t0 + t1 + t2;
        t0 = t1; t1 = t2; t2 = t3;
    }

    return t2;
}

int main()
{
    cout << tribonacci(4) << endl;
    cout << tribonacci(25) << endl;
    return 0;
}

