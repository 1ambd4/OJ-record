#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#include "leetcode.h"

using namespace std;

int max_length_between_equal_chararcters(string s)
{
    int n = s.size(), res = -1;
    vector<int> idx(30, -1);

    for (int i = 0; i < n; ++i) {
        if (idx[s[i] - 'a'] != -1) {
            res = max(res, i - idx[s[i] - 'a'] - 1);
        } else {
            idx[s[i] - 'a'] = i;
        }
    }

    return res;
}

int main()
{
    string s1 { "aa" };
    cout << max_length_between_equal_chararcters(s1) << endl;

    string s2 { "abca" };
    cout << max_length_between_equal_chararcters(s2) << endl;

    string s3 { "cbzxy" };
    cout << max_length_between_equal_chararcters(s3) << endl;

    string s4 { "cabbac" };
    cout << max_length_between_equal_chararcters(s4) << endl;

    string s5 { "mgntdygtxrvxjnwksqhxuxtrv" };
    cout << max_length_between_equal_chararcters(s5) << endl;
    return 0;
}

