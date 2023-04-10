#include <iostream>
#include <cmath>

using namespace std;

// aarch64可以用汇编
// long lround(double x)
// {
// 	long n;
// 	__asm__ ("fcvtas %x0, %d1" : "=r"(n) : "w"(x));
// 	return n;
// }

int main()
{
    double d = 0;
    while (cin >> d) {
        // cout << (int)(d + 0.5) << endl;
        cout << round(d) << endl;
    }
    return 0;
}
