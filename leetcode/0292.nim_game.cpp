#include <iostream>
#include <vector>
#include <cstdio>

bool can_win_nim(int n)
{
    return n % 4 != 0;
}

int main()
{
#ifdef LOCAL
    freopen("0292.in", "r", stdin);
#endif
    int n = 0;
    while (std:: cin >> n) {
        std::cout << can_win_nim(n) << std::endl;
    }

    return 0;
}

