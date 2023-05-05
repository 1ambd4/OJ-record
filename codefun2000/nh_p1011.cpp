#include <iostream>
#include <vector>
#include <cstdio>

int main()
{
#ifdef LOCAL
    freopen("nh_p1011.in", "r", stdin);
#endif
    std::string s;
    while (std::cin >> s) {
        std::cout << s.substr(0, 8) << " ";
    }

    return 0;
}

