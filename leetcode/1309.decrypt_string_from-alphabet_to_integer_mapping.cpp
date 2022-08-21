#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

string freq_alphabets_(string s)
{
    string res {};
    int n = s.size();

    map<int, char> m;
    for (int i = 1; i <= 9; ++i) m[i] = 'a' + i - 1;
    for (int i = 10; i <= 26; ++i) m[i] = 'a' + i - 1;

    for (int i = 0; i < n-2; ++i) {
        if (s[i+2] == '#') {
            int t = (s[i]-'0') * 10 + (s[i+1]-'0');
            res += m[t];
            ++i, ++i;
        } else {
            res += m[s[i]-'0'];
        }
    }

    if (s[n-1] != '#') {
        res += m[s[n-2]-'0'];
        res += m[s[n-1]-'0'];
    }

    return res;
}

// 反向
string freq_alphabets(string s)
{
    string res {};
    int n = s.size();

    for (int i = n - 1; i >= 0; --i) {
        int offset = s[i] == '#' ? s[--i] - '1' + (s[--i] - '0') * 10 : s[i] - '1';
        res += 'a' + offset;
    }
    reverse(res.begin(), res.end());

    return res;
}

int main()
{
    string s1 { "10#11#12" };
    cout << freq_alphabets(s1) << endl;

    string s2 { "1326#" };
    cout << freq_alphabets(s2) << endl;

    string s3 { "26#11#418#5" };
    cout << freq_alphabets(s3) << endl;
    return 0;
}

