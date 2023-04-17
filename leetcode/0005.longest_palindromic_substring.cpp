#include <iostream>
#include <string>

// 马拉车板子题啊？


// 中心扩散
std::string longest_palindrome(std::string s)
{
    std::string res {""};
    int n = s.size();

    auto palindrome = [&res, n](std::string s, int l, int r) -> void {
        while (l >= 0 && r < n && s[l] == s[r]) {
            --l;
            ++r;
        }
        std::string t = s.substr(l+1, r-l-1);
        if (t.size() > res.size()) res = t;
    };

    for (int i = 0; i < n; ++i) {
        palindrome(s, i, i);
        palindrome(s, i, i+1);
    }

    return res;
}


int main()
{
    std::string s1 = "babad";
    std::cout << longest_palindrome(s1) << std::endl;

    return 0;
}
