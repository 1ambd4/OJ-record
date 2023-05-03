#include <iostream>
#include <vector>
#include <cstdio>
#include <iterator>
#include <string>
#include <algorithm>

std::string replace_space(std::string s)
{
    int c = 0, n = s.size();
    std::for_each(s.begin(), s.end(), [&c](const char ch){
            if (ch == ' ') ++c;
    });

    // 一个空格被替换成三个字符，因而每个空格需要多占两个字符
    int m = n + c * 2;
    s.resize(m);

    int p1 = n - 1, p2 = m - 1;
    while (p1 >= 0 && p2 > p1) {
        if (s[p1] == ' ') {
            s[p2--] = '0';
            s[p2--] = '2';
            s[p2--] = '%';
        } else {
            s[p2--] = s[p1];
        }
        --p1;
    }

    return s;
}

int main()
{
#ifdef LOCAL
    freopen("05.in", "r", stdin);
#endif
    std::string s;
    while (getline(std::cin, s)) {
        std::cout << replace_space(s) << std::endl;
    }

    return 0;
}

