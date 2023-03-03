#include <iostream>
#include <vector>

using namespace std;

bool is_subsequence(string s, string t)
{
    int i = 0, j = 0;
    while (i < s.size() && j < t.size()) {
        if (s[i] == t[j]) ++i;
        ++j;
    }
    return i == s.size();
}

int main()
{
    string s1 {"abc"}, t1 {"ahbgdc"};
    cout << is_subsequence(s1, t1) << endl;

    string s2 {"axc"}, t2 {"ahbgdc"};
    cout << is_subsequence(s2, t2) << endl;

    return 0;
}

