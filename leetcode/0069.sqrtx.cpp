#include <iostream>
#include <cmath>

using namespace std;

// 二分查找
int my_sqrt(int x)
{
    int left = 0, right = x;
    while (left <= right) {
        int mid = left + ((right-left) >> 1);
        if (mid > x * 1.0 / mid) {
            right = mid - 1;
        } else {
            if ((mid + 1) > x * 1.0  / (mid + 1)) {
                return mid;
            } else {
                left = mid + 1;
            }
        }
    }
}

// 牛顿迭代法
int newton_iterative_method(int n)
{
    if (n == 0) return 0;

    double C = n, x = n;
    while (true) {
        double X = 0.5 * ( x + C / x);
        if (fabs(x - X) < 1e-9) {
            break;
        }
        x = X;
    }
    return int(x);
}

int main()
{
    cout << newton_iterative_method(0) << endl;
    cout << newton_iterative_method(1) << endl;
    cout << newton_iterative_method(4) << endl;
    cout << newton_iterative_method(8) << endl;
    cout << newton_iterative_method(9) << endl;
    return 0;
}
