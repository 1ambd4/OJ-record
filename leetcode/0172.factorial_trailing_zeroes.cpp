#include <iostream>
#include <vector>
#include <cstdio>

int trailing_zeros(int n)
{
    if (n == 0) return 0;

    int cnt = 0;
    while (n != 0) {
        cnt += n / 5;
        n /= 5;
    }

    return cnt;
}

int main()
{
#ifdef LOCAL
    freopen("0172.in", "r", stdin);
#endif
    int n = 0;
    while (std::cin >> n) {
        std::cout << trailing_zeros(n) << std::endl;
    }

    return 0;
}

