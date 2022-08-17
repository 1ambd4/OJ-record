#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool is_robot_bounded(string instructions)
{
    instructions += instructions;
    instructions += instructions;

    // distance[0...4]: 北东南西
    vector<int> distance(4, 0);

    // 0: 北，1: 东，2: 南，3: 西
    int orientation = 0;

    for (const auto& op : instructions) {
        if (op == 'G') {
            ++distance[orientation];
        } else if (op == 'L') {
            orientation = (orientation - 1 + 4) % 4;
        } else if (op == 'R') {
            orientation = (orientation + 1) % 4;
        }
    }

    if (distance[0] == distance[2] && distance[1] == distance[3]) return true;
    return false;
}

int main()
{
    string instructions1 { "GGLLGG" };
    cout << is_robot_bounded(instructions1) << endl;

    string instructions2 { "GG" };
    cout << is_robot_bounded(instructions2) << endl;

    string instructions3 { "GL" };
    cout << is_robot_bounded(instructions3) << endl;
    return 0;
}

