#include <iostream>
#include <vector>

#include "leetcode.h"

using namespace std;

bool check_straight_line(vector<vector<int>>& coordinates)
{
    int n = coordinates.size();

    if (n == 2) return true;

    if (coordinates[1][0] == coordinates[0][0]) {
        for (int i = 2; i < n; ++i) {
            if (coordinates[i][0] != coordinates[0][0]) {
                return false;
            }
        }
        return true;
    } 

    double k = (1.0 * coordinates[1][1] - coordinates[0][1]) / (coordinates[1][0] - coordinates[0][0]);
    double b = (1.0 * coordinates[0][1] - k * coordinates[0][0]);

    for (int i = 2; i < n; ++i) {
        if (coordinates[i][1] != k * coordinates[i][0] + b) {
            return false;
        }
    }
    return true;
}

int main()
{
    vector<vector<int>> points1 { {1,2}, {2,3}, {3,4}, {4,5}, {5,6}, {6,7} };
    cout << check_straight_line(points1) << endl;

    vector<vector<int>> points2 { {1,1}, {2,2}, {3,4}, {5,6}, {7,7} };
    cout << check_straight_line(points2) << endl;

    vector<vector<int>> points3 { {2,1}, {4,2}, {6,3} };
    cout << check_straight_line(points3) << endl;

    return 0;
}

