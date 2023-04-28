#include <iostream>
#include <vector>
#include <cstdio>

bool is_palindrome(std::string s)
{
    auto check = [](const char ch) -> bool {
        return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9');
    };

    int l = 0, r = 0;
    int n = s.size();
    while (r < n) {
        if (check(s[r])) s[l++] = (s[r] | 0b0010'0000);
        ++r;
    }

    r = l-1, l = 0;
    int ml = (r - l) >> 1, mr = (r - l + 1) >> 1;
    while (ml >= l && mr <= r && s[ml] == s[mr]) {
        --ml;
        ++mr;
    }

    if (ml == l-1 && mr == r+1) return true;
    else return false;
}

int main()
{
#ifdef LOCAL
    freopen("0125.in", "r", stdin);
#endif
    std::string s;
    while (getline(std::cin, s)) {
        std::cout << is_palindrome(s) << std::endl;
    }

    return 0;
}
