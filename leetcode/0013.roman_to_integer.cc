#include <iostream>
#include <cstring>
#include <unordered_map>

using namespace std;

// 如果当前字符代表的值不小于其右边的那个，加上该值，否则减去
int roman_to_int(string s)
{
    int res = 0;
    unordered_map<char, int> m{
        {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}
    };
    
    for (int i = 0, len = s.size(); i < len-1; ++i) {
        if (m[s[i]] < m[s[i+1]]) {
            res -= m[s[i]];
        } else {
            res += m[s[i]];
        }
    }

    return res + m[s[s.size()-1]];

}

int main()
{
    cout << roman_to_int("III") << endl;
    cout << roman_to_int("IV") << endl;
    cout << roman_to_int("IX") << endl;
    cout << roman_to_int("LVIII") << endl;
    cout << roman_to_int("MCMXCIV") << endl;
    return 0;
}
