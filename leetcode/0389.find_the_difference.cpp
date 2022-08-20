#include <iostream>
#include <vector>

using namespace std;

char find_the_difference_(string s, string t)
{
    vector<int> cnt(26, 0);
    for (const auto& c : s) {
        ++cnt[c-'a'];
    }
    for (const auto& c : t) {
        if (--cnt[c-'a'] < 0) {
            return c;
        }
    }
}

// 两个字符串里，找到出现奇数次的那个
char find_the_difference(string s, string t)
{
    s += t;
    int sum = 0;
    for (const auto& c : s) {
        sum ^= c;
    }
    return sum;
}

int main()
{
    string s1 { "abcd" }, t1 { "abcde" };
    cout << find_the_difference(s1, t1) << endl;

    string s2 { "" }, t2 { "y" };
    cout << find_the_difference(s2, t2) << endl;
    return 0;
}

