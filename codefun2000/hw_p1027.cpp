#include <iostream>
#include <string>
#include <vector>
#include <cstdio>


int main()
{
    std::cin.tie(0); std::cout.tie(0);
    std::string s;

    while (std::cin >> s) {

        int n = s.size();
        std::vector<int> a(n);

        // 字符串移位替换，注意取模就好
        a[0] = 1, a[1] = 2, a[2] = 4;
        for (int i{3}; i < n; ++i) {
            a[i] = (a[i-1] + a[i-2] + a[i-3]) % 26;
        }
        for (int i = 0; i < s.size(); ++i) {
            printf("%c", 'a' + (s[i] - 'a' + a[i]) % 26);
        }
        printf("\n");
    }

    return 0;
}
