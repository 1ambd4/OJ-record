#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

int min_operations(vector<string>& logs)
{
    stack<string> s;

    for (const auto& log : logs) {
        if (log[0] == '.') {
            if (log[1] == '.' && !s.empty()) {
                s.pop();
            }
        } else {
            s.push(log);
        }
    }

    return s.size();
}

int main()
{
    vector<string> log1 { "d1/", "d2/", "../", "d21", "./" };
    cout << min_operations(log1) << endl;

    vector<string> log2 { "d1/", "d2/", "./", "d3/", "../", "d31/" };
    cout << min_operations(log2) << endl;

    vector<string> log3 { "d1/", "../", "../", "../" };
    cout << min_operations(log3) << endl;
    return 0;
}

