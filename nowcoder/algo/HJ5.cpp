#include <iostream>
#include <stack>
#include <map>
#include <string>
#include <cmath>

using namespace std;

int main()
{
    stack<char> stk;
    map<char, int> m;

    for (char c = '0'; c <= '9'; ++c) m[c] = c - '0';
    for (char c = 'a'; c <= 'f'; ++c) m[c] = c - 'a' + 10;
    for (char c = 'A'; c <= 'F'; ++c) m[c] = c - 'A' + 10;

    string s;
    while (getline(cin, s)) {
        int n = s.size();
        for (int i = 2; i < n; ++i) stk.push(s[i]);

        int res = 0, cnt = 0;
        while (!stk.empty()) {
            res += (m[stk.top()] * pow(16, cnt++));
            stk.pop();
        }

        cout << res << endl;
    }
    return 0;
}
