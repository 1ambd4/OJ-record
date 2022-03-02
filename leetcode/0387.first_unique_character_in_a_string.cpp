#include <iostream>
#include <string>
#include <vector>

using namespace std;

int first_unique_char(string s)
{
    vector<int> cnt(26, 0);
    for (const char& ch : s) {
        cnt[ch - 'a']++;
    }

    for (int i = 0; i < s.size(); ++i) {
        if (cnt[s[i] - 'a'] == 1) {
            return i;
        }
    }
    
    return -1;
}

int main()
{
    cout << first_unique_char("leetcode") << endl;
    cout << first_unique_char("loveleetcode") << endl;
    return 0;
}
