#include <iostream>
#include <vector>
#include <cstdio>
#include <limits>

// 数学定理：任何正整数都可以拆分成不超过4个数的平方和
// 即此题答案只可能是1、2、3、4
// （平方和最多张成四维空间？
// 1.如果一个数最少可以拆成4个数的平方和，则有数n=(4^a) * (8b + 7)
// 2.如果这个数本来就是某个数的平方，那么答案就是1,否则只能是2或3
// 3.显然2好计算些，遍历所有的n=a^2 + b^2即可
// 4.否则答案为3
int _nums_squares(int n)
{
    while (n % 4 == 0) n /= 4;
    if (n % 8 == 7) return 4;

    for(int i = 0; i * i <= n; ++i) {
        if (n - i * i == 0) return 1;
    }

    for (int i = 0; i * i < n; ++i) {
        for (int j = 0; j * j < n; ++j) {
            if (n - i * i - j * j == 0) return 2;
        }
    }

    return 3;
}

// 完全背包
int nums_squares(int n)
{
    std::vector<int> dp(n+1, std::numeric_limits<int>::max());
    dp[0] = 0;

    for (int i = 0; i <= n; ++i) {
        for (int j = 1; j * j <= i; ++j) {
            dp[i] = std::min(dp[i - j * j] + 1, dp[i]);
        }
    }

    return dp[n];
}

int main()
{
#ifdef LOCAL
    freopen("0279.in", "r", stdin);
#endif

    int n = 0;
    while (std::cin >> n) {
        std::cout << nums_squares(n) << std::endl;
    }

    return 0;
}

