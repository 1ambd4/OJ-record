#include <iostream>
#include <vector>
#include <limits>

using namespace std;

int nearest_valid_point(int x, int y, vector<vector<int>>& points)
{
    int minimum = numeric_limits<int>::max(), index = -1, index_sum = -1;

    for (int i = 0; i < points.size(); ++i) {
        if (points[i][0] == x || points[i][1] == y) {
            int distance = abs(points[i][0] - x) + abs(points[i][1] - y);
            if (distance < minimum) {
                minimum = distance;
                index = i;
                index_sum = points[i][0] + points[i][1];
            } else if (distance == minimum) {
                if (points[i][0] + points[i][1] < index_sum) {
                    index = i;
                    index_sum = points[i][0] + points[i][1];
                }
            }
        }
    }

    if (index == -1) return -1;

    return index;
}

int main()
{
    vector<vector<int>> points1 { {1,2}, {3,1}, {2,4}, {2,3}, {4,4} };
    cout << nearest_valid_point(3, 4, points1) << endl;

    vector<vector<int>> points2 { {3,4} };
    cout << nearest_valid_point(3, 4, points2) << endl;

    vector<vector<int>> points3 { {2,3} };
    cout << nearest_valid_point(3, 4, points3) << endl;

    return 0;
}

