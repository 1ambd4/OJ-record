#include <iostream>
#include <vector>
#include <string>

using namespace std;

int vowel_strings(vector<string>& words, int left, int right)
{
    int res = 0;
    if (words.size() == 0) return res;

    auto check = [](const char ch) -> bool {
        switch(ch) {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
                return true;
            default:
                return false;
        }
    };

    for (int i = left; i <= right; ++i) {
        if (check(words[i][0]) && check(words[i][words[i].size()-1])) {
            ++res;
        }
    }

    return res;
}

int main()
{
    vector<string> words1 {"are", "amy", "u"};
    cout << vowel_strings(words1, 0, 2) << endl;

    return 0;
}

