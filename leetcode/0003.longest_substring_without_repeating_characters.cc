#include <iostream>
#include <cstring>
#include <unordered_map>

using namespace std;

// 滑动窗口
int length_of_longest_substring(string s)
{
    int left = 0, right = 0, res = 0;
    unordered_map<char, int> window;

    while (right < s.size()) {
        char c = s[right];
        ++right;
        ++window[c];

        while (window[c] > 1) {
            char d = s[left];
            ++left;
            --window[d];
        }

        res = max(res, right - left);
    }

    return res;
}

int main()
{
    cout << length_of_longest_substring("abcabcb") << endl;
    cout << length_of_longest_substring("bbbb") << endl;
    cout << length_of_longest_substring("pwwkew") << endl;
    return 0;
}
