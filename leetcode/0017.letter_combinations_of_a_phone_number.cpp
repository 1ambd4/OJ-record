#include <iostream>
#include <vector>
#include <string>

#include "leetcode.h"

using namespace std;

vector<string> letter_combinations(string digits)
{
    int n = digits.size();
    vector<string> res;

    if (n == 0) return res;

    vector<string> m{"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    string s = "";

    auto backtrack = [&m, &n, &res](auto&& self, const string& digits, int id, string& s) -> void {
        // 边界情况保存结果
        if (s.size() == n) res.push_back(s);

        // 其余可能的选择
        for (int i = id; i < n; ++i) {
            int num = digits[i] - '0';
            for (char& c : m[num]) {
                // s.append(string(c));
                s.push_back(c);
                self(self, digits, i+1, s);
                s.pop_back();
            }
        }
    };

    backtrack(backtrack, digits, 0, s);

    return res;
}

int main()
{
    string digits1 {"23"};
    vector<string> res1 = letter_combinations(digits1);
    cout << res1 << endl;
    return 0;
}

