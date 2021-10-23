#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool is_anagram(string s, string t)
{
    int len1 = s.size(), len2 = t.size();
    if (len1 != len2) {
        return false;
    }

    vector<vector<int>> cnt(2, vector<int>(26, 0));
    for (int i = 0; i < len1; ++i) {
        cnt[0][s[i]-'a']++;
        cnt[1][t[i]-'a']++;
    }

    for (int i = 0; i < 26; ++i) if (cnt[0][i] != cnt[1][i]) {
        return false;
    }

    return true;
}

int main()
{
    cout << is_anagram("anagram", "nagaram") << endl;
    cout << is_anagram("rat", "cat") << endl;
    return 0;
}
