#include <iostream>
#include <vector>
#include <cstdio>
#include <string>

std::string time_coincide(int t)
{
    if (t == 11) return "12:00";
    if (t == 23) return "0:00";
    int m = (int) ((t % 12) * 60.0 / 11 + 0.5);
    if (m < 10) {
        return std::to_string(t) + ":0" + std::to_string(m);
    }
    return std::to_string(t) + ":" + std::to_string(m);
}

int main()
{
#ifdef LOCAL
    freopen("nh_p1008.in", "r", stdin);
#endif
    int n = 0;
    while (std::cin >> n) {
        std::cout << time_coincide(n) << std::endl;
    }

    return 0;
}

