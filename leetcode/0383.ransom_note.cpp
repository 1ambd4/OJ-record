#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool can_construct(string ransom, string magazine)
{
    vector<int> cnt(26, 0);

    for (const char& ch : ransom) {
        cnt[ch - 'a']++;
    }
    for(const char& ch : magazine) {
        cnt[ch - 'a']--;
    }
    for (const int& i : cnt) if (i > 0) {
        return false;
    }

    return true;
}

int main()
{
    cout << can_construct("a", "b") << endl;
    cout << can_construct("aa", "ab") << endl;
    cout << can_construct("aa", "aab") << endl;
    return 0;
}
