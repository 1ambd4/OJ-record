#include <iostream>
#include <vector>
#include <cstdio>
#include <string>
#include <sstream>
#include <cmath>

int main()
{
#ifdef LOCAL
    freopen("./hw_p1041.in", "r", stdin);
#endif
    std::string s;
    while (std::getline(std::cin, s)) {
        unsigned long long sum = 0, cnt = 0;
        std::stringstream ss(s);
        while (ss >> s) {
            sum += s.size();
            ++cnt;
        }

        printf("%.2lf\n", sum / (double)cnt);
    }
    return 0;
}

