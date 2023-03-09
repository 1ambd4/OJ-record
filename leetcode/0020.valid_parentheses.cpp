#include <iostream>
#include <stack>

using namespace std;

bool is_valid(string s)
{
    stack<char> stk;

    auto left = [](char c) ->char {
        switch(c) {
            case ')':
                return '(';
            case ']':
                return '[';
            case '}':
                return '{';
        }
    };

    for (const auto& c : s) {
        if (c == '(' || c == '[' || c == '{') {
            stk.push(c);
        } else {
            if (stk.empty() || stk.top() != left(c)) {
                return false;
            } else {
                stk.pop();
            }
        }
    }

    if (!stk.empty()) {
        return false;
    }

    return true;
}

bool _is_valid(string s)
{
    stack<char> stk;
    for (const char& ch : s) {
        if (ch == '(') stk.push(')');
        else if (ch == '{') stk.push('}');
        else if (ch == '[') stk.push(']');
        else {
            if (stk.empty() || ch != stk.top()) {
                return false;
            } else {
                stk.pop();
            }
        }
    }

    if (!stk.empty()) {
        return false;
    }

    return true;
}

int main()
{
    cout << is_valid("()") << endl;
    cout << is_valid("()[]{}") << endl;
    cout << is_valid("(]") << endl;
    cout << is_valid("[") << endl;
    cout << is_valid("]") << endl;

    return 0;
}
