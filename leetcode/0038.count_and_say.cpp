#include <iostream>
#include <vector>
#include <cstdio>
#include <sstream>

// 这数据规模，我是很想打表的
std::string count_and_say(int n)
{
    if (n == 1) return "1";
    if (n == 2) return "11";

    std::string res {"11"};

    auto rec = [&res, &n](auto&& self, int i) {
        char num = 0, tmp = 0;
        int cnt = 1;
        std::string s { res };
        res = "";
        std::stringstream ss(s);
        ss >> num;
        while (ss >> tmp) {
            if (tmp == num) ++cnt;
            else {
                res += std::to_string(cnt);
                res += std::to_string(num-'0');
                cnt = 1;
                num = tmp;
            }
        }

        res += std::to_string(cnt);
        res += std::to_string(num - '0');

        if (i + 1 == n) return ;
        else self(self, i + 1);
    };

    rec(rec, 2);

    return res;
}

int main()
{
#ifdef LOCAL
    freopen("0038.in", "r", stdin);
#endif
    int n = 0;
    while (std::cin >> n) {
        std::cout << count_and_say(n) << std::endl;
    }
    return 0;
}

