#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

#include "leetcode.h"

using namespace std;

vector<int> find_anagrams(string s, string p)
{
    vector<int> res;
    unordered_map<char,int> need, window;
    int left = 0, right = 0, valid = 0, len = 0;

    for (const char &c : p) {
        need[c]++;
    }

    while (right < s.size()) {
        // 右扩
        char c = s[right++];
        if (need.count(c)) {
            window[c]++;
            if (window[c] == need[c]) {
                valid++;
            }
        }

        while (valid == need.size()) {
            // 更新答案
            if (right-left == p.size()) {
                res.push_back(left);
            }
            
            // 左缩
            char c = s[left++];
            if (need.count(c)) {
                if (window[c] == need[c]) {
                    valid--;
                }
                window[c]--;
            }
        }
    }

    return res;
}

int main()
{
    string s1 = "cbaebabacd", p1 = "abc";
    vector<int> res1 = find_anagrams(s1, p1);
    print_vector<int>(res1);
    string s2 = "abab", p2 = "ab";
    vector<int> res2 = find_anagrams(s2, p2);
    print_vector<int>(res2);
    return 0;
}
