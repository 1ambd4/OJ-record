#include <iostream>
#include <vector>
#include <cstdio>

int hamming_weight(uint32_t n)
{
    int cnt = 0;

    while (n) {
        n = n & (n-1);
        ++cnt;
    }

    return cnt;
}

int main()
{
#ifdef LOCAL
    freopen("15.in", "r", stdin);
#endif
    uint32_t n = 0;
    while (std::cin >> n) {
        std::cout << hamming_weight(n) << std::endl;
    }

    return 0;
}

