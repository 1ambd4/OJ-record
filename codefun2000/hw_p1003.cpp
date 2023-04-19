#include <iostream>
#include <vector>
#include <cstdio>
#include <limits>

// 弟弟的加法其实就是异或
// 那如果想要可以平分的话，就需要所有数字的异或结果为0
// 问题是如何分呢？
// 其实只要把最小的一块给弟弟即可
// 因为全部的异或和为0的情况下，任意一个与其余全部的异或和定然为0
int main()
{
#ifdef LOCAL
    freopen("./hw_p1003.in", "r", stdin);
#endif

    int n;
    while (std::cin >> n) {
        std::vector<int> w(n);
        int summ = 0, minn = std::numeric_limits<int>::max(), xorr = 0;
        for (int i{0}; i < n; ++i) {
            std::cin >> w[i];
            xorr ^= w[i];
            summ += w[i];
            minn = std::min(minn, w[i]);
        }
        if (xorr != 0) {
            std::cout << "NO" << std::endl;
        } else {
            std::cout << summ - minn << std::endl;
        }
    }
    return 0;
}

