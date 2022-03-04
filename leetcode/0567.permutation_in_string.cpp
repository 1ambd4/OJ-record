#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

// s1 是模式串，s2是主串
bool check_inclusion(string s1, string s2)
{
    int left = 0, right = 0, valid = 0;
    unordered_map<char, int> need, window;

    for (const char &c : s1) {
        need[c]++;
    }

    while (right < s2.size()) {
        // 右扩
        char c = s2[right++];
        if (need.count(c)) {
            window[c]++;
            if (window[c] == need[c]) {
                valid++;
            }
        }

        while (valid == need.size()) {
            // 更新答案
            if (right-left == s1.size()) {
                return true;
            } 

            // 左缩
            char c = s2[left++];
            if (need.count(c)) {
                if (window[c] == need[c]) {
                    valid--;
                }
                window[c]--;
            }
        }
    }

    return false;
}

int main()
{
    string s1 = "eidbaooo", t1 = "ab";
    cout << check_inclusion(t1, s1) << endl;
    string s2 = "eidboall", t2 = "ba";
    cout << check_inclusion(t2, s2) << endl;
    return 0;
}
