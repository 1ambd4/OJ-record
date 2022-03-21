#include <iostream>
#include <stack>
#include <string>

using namespace std;

int min_add_to_make_valid(string s)
{
    stack<char> stk;
    int res = 0;
    for (const char& ch : s) {
        if (ch == '(') stk.push(')');
        else {
            if (stk.empty() || ch != stk.top()) {
                res++;
            } else {
                stk.pop();
            }
        }
    }
    return res + stk.size();
}

int main()
{
    string s1 {"())"};
    cout << min_add_to_make_valid(s1) << endl;
    string s2 {"((("};
    cout << min_add_to_make_valid(s2) << endl;
    return 0;
}
