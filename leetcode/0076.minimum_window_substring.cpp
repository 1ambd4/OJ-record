#include <climits>
#include <iostream>
#include <unordered_map>
#include <string>
#include <limits>

using namespace std;

string min_window(string s, string t)
{
    int left = 0, right = 0, valid = 0;
    int start = 0, len = numeric_limits<int>::max();
    unordered_map<char, int> need, window;

    for (const auto& c: t) need[c]++;

    while (right < s.size()) {
        char c = s[right++];
        if (need.count(c)) {
            window[c]++;
            if (window[c] == need[c]) ++valid;
        }

        while (valid == need.size()) {
            if (right - left < len) {
                start = left;
                len = right - left;
            }

            char c = s[left++];
            if (need.count(c)) {
                if (window[c] == need[c]) --valid;
                window[c]--;
            }
        }
    }

    return len == numeric_limits<int>::max() ? "" : s.substr(start, len);
}


// 滑动窗口，右扩找可行解，左缩优化解
string _min_window(string s, string t)
{
    int left = 0, right = 0, valid = 0;
    int start = 0, len = INT_MAX;
    unordered_map<char, int> need, window;
    for (const char &c : t) {
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
            // 更新记录
            if (right - left < len) {
                start = left;
                len = right - left;
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

    return len == INT_MAX ? "" : s.substr(start, len);
}

int main()
{
    string s1 = "ADOBECODEBANC", t1 = "ABC";
    cout << min_window(s1, t1) << endl;

    string s2 = "a", t2 = "a";
    cout << min_window(s2, t2) << endl;

    string s3 = "a", t3 = "aa";
    cout << min_window(s3, t3) << endl;

    return 0;
}
