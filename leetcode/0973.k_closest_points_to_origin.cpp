#include <iostream>
#include <vector>
#include <queue>

#include "leetcode.h"

using namespace std;

vector<vector<int>> k_closet(vector<vector<int>>& points, int k)
{
    auto cmp = [](vector<int>& a, vector<int>& b){
        return (a[0] * a[0] + a[1] * a[1]) < (b[0] * b[0] + b[1] * b[1]);
    };
    priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> q(cmp);

    q.push(points[0]);

    for (int i = 1; i < points.size(); ++i) {
        if (q.size() < k) {
            q.push(points[i]);
        } else {
            int d1 = q.top()[0] * q.top()[0] + q.top()[1] * q.top()[1];
            int d2 = points[i][0] * points[i][0] + points[i][1] * points[i][1];
            if (d2 < d1) {
                if (q.size() >= k) q.pop();
                q.push(points[i]);
            }
        }
    }


    vector<vector<int>> res;
    while (!q.empty()) {
        res.push_back(q.top());
        q.pop();
    }

    return res;
}

int main()
{
    vector<vector<int>> points1 { {1,3}, {-2,2}, {4, 7} };
    vector<vector<int>> res1 = k_closet(points1, 3);
    cout << res1 << endl;

    vector<vector<int>> points2 { {3,3}, {5,-1}, {2,4} };
    vector<vector<int>> res2 = k_closet(points2, 2);
    cout << res2 << endl;
    return 0;
}
