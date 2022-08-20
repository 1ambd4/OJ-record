#include <iostream>
#include <vector>

using namespace std;

string interpret(string command)
{
    string res {};
    auto it = command.begin();
    while (it != command.end()) {
        if (*it == 'G') {
            res += *it++;
        } else if (*it == '(') {
            if (*(it+1) == ')') {
                res += 'o';
                it += 2;
            } else {
                res += "al";
                it += 4;
            }
        }
    }
    return res;
}

int main()
{
    string command1 { "G()(al)" };
    cout << interpret(command1) << endl;

    string command2 { "G()()()()(al)" };
    cout << interpret(command2) << endl;

    return 0;
}

