#include <iostream>
#include <string>
#include <stack>

using namespace std;

int min_insertions(string s)
{
    // res为需要插入的次数，need为需要的右括号数
    int res = 0, need = 0;

    for (const auto& c : s) {
        if (c == '(') {
            need += 2;
            // 当遇到左括号时，若右括号数为奇数
            // 说明前面为匹配，需要插入一个右括号
            if (need % 2 == 1) {
                // need++;
                need--;
                res++;
            }
        } else {
            need--;
            if (need == -1) {
                res++;
                need = 1;
            }
        }
    }

    return res + need;
}

// 过不了testcase8
// int min_insertions(string s)
// {
//     stack<char> stk;
//     int res = 0;
//
//     for (const char& ch : s) {
//         if (ch == '(') {
//             if (stk.size() % 2 == 1) {  // 针对类似case6的情况处理
//                 stk.pop();
//                 res += 2;
//             }
//             stk.push(')');
//             stk.push(')');
//         } else {
//             if (stk.empty() || stk.top() != ch) {
//                 res++;
//             } else {
//                 stk.pop();
//             }
//         }
//     }
//
//     return stk.size() + (res+1)/2 + res%2;
// }

int _min_insertions(string s)
{
    // need记录右括号的需求数量
    int res = 0, need = 0;
    for (const char& ch : s) {
        if (ch == '(') {
            need += 2;
            if (need % 2 == 1) {
                need--;
                res++;
            }
        } else if (ch == ')') {
            need--;
            if (need == -1) {
                need = 1;
                res++;
            }
        }
    }

    return res + need;
}

int main()
{
    string s1 = "(()))";
    cout << min_insertions(s1) << endl;
    string s2 = "())";
    cout << min_insertions(s2) << endl;
    string s3 = "))())(";
    cout << min_insertions(s3) << endl;
    string s4 = "((((((";
    cout << min_insertions(s4) << endl;
    string s5 = ")))))))";
    cout << min_insertions(s5) << endl;
    string s6 = "(()))(()))()())))";
    cout << min_insertions(s6) << endl;
    string s7 = "()()()()()(";
    cout << min_insertions(s7) << endl;
    string s8 = "))(()()))()))))))()())()(())()))))()())(()())))()(";
    cout << min_insertions(s8) << endl;
    string s9 {"()()()()()("};
    cout << min_insertions(s9) << endl;

    return 0;
}
