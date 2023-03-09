#include <iostream>
#include <stack>
#include <string>

using namespace std;

int min_add_to_make_valid(string s)
{
    int res = 0, need = 0;

    for (const auto& c : s) {
        if (c == '(') {
            need++;
        } else {
            need--;
            if (need ==  -1) {
                res++;
                need = 0;
            }
        }
    }

    return res + need;
}

// 无法处理"()))(("
int __min_add_to_make_valid(string s)
{
    int res = 0;

    for (const auto& c : s) {
        if (c == '(') {
            res++;
        } else if (c == ')') {
            res--;
            if (res == -1) res =  1;
        }
    }

    return res;
}

int _min_add_to_make_valid(string s)
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
    string s3 {"()))(("};
    cout << min_add_to_make_valid(s3) << endl;

    return 0;
}
