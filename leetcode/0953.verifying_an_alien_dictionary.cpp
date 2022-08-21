#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <algorithm>

#include "leetcode.h"

using namespace std;

bool is_alien_sorted(vector<string>& words, string order)
{
    vector<int> cti(26, 0);
    for (int i = 0; i < 26; ++i) {
        cti[order[i]-'a'] = i;
    }

    // s1 < s2
    auto cmp = [&cti](string s1, string s2) {
        auto it1 = s1.begin(), it2 = s2.begin();
        while (it1 != s1.end() && it2 != s2.end()) {
            if (cti[*it1-'a'] < cti[*it2-'a']) return true;
            else if (cti[*it1-'a'] > cti[*it2-'a']) return false;
            else if (cti[*it1-'a'] == cti[*it2-'a']) ++it1, ++it2;
        }
        if (it1 != s1.end()) return false;
        if (it2 != s2.end()) return true;
        return false;
    };

    return is_sorted(words.begin(), words.end(), cmp);
}

int main()
{
    vector<string> words1 { "hello", "leetcode" };
    string order1 { "hlabcdefgijkmnopqrstuvwxyz" };
    cout << is_alien_sorted(words1, order1) << endl;

    vector<string> words2 { "word", "world", "row" };
    string order2 { "worldabcefghijkmnpqstuvxyz" };
    cout << is_alien_sorted(words2, order2) << endl;


    vector<string> words3 { "apple", "app" };
    string order3 { "abcdefghijklmnopqrstuvwxyz" };
    cout << is_alien_sorted(words3, order3) << endl;

    vector<string> words4 { "hello", "hello" };
    string order4 { "abcdefghijklmnopqrstuvwxyz" };
    cout << is_alien_sorted(words4, order4) << endl;

    vector<string> words { "a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "w", "v", "u", "x", "y", "z" };
    cout << is_alien_sorted(words, order3) << endl;
    return 0;
}
