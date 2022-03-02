#include <iostream>
#include <stack>

using namespace std;

bool is_valid(string s)
{
    stack<char> stk;
    for (const char& ch : s) {
        if (ch == '(') stk.push(')');
        else if (ch == '{') stk.push('}');
        else if (ch == '[') stk.push(']');
        else {
            if (stk.empty() || stk.top() != ch) {
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
