#include <iostream>
#include <cstring>
#include <unordered_map>

using namespace std;

int length_of_longest_substring(string s)
{
    int left = 0, right = 0, res = 0;
    unordered_map<char, int> window;

    while (right < s.size()) {
        char c = s[right++];
        window[c]++;

        // 当前字符添加后，若出现重复字符，则将移动左窗口收束左边界
        while (window[c] > 1) {
            char c = s[left++];
            window[c]--;
        }

        // 因为此题左边界收束的条件不同
        // 因而答案的更新位置不同于其他滑动窗口题
        // 要在左边界收束完成之后才能保证无重复字符
        res = max(res, right-left);
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
