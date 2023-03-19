#include <iostream>
#include <vector>
#include <algorithm>

#include "leetcode.h"

using namespace std;

int min_cost_connect_points(vector<vector<int>>& points)
{
    int n = points.size();
    vector<int> parent(n), size(n, 0);
    for (int i = 0; i < n; ++i) parent[i] = i;

    vector<vector<int>> edges;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int xi = points[i][0], yi = points[i][1];
            int xj = points[j][0], yj = points[j][1];
            edges.push_back({i, j, abs(xi-xj) + abs(yi-yj)});
        }
    }

    sort(edges.begin(), edges.end(), [](vector<int>& a, vector<int>& b) {
            return a[2] < b[2];
    });

    auto find = [&parent](int x) -> int {
        while (parent[x] != x) {
            parent[x] = parent[parent[x]];
            x = parent[x];
        }

        return x;
    };

    auto merge = [&parent, &size, &find](int x, int y) -> bool {
        int rx = find(x), ry = find(y);

        if (rx == ry) return false;

        if (size[rx] > size[ry]) {
            parent[ry] = rx;
            size[rx] += size[ry];
        } else {
            parent[rx] = ry;
            size[ry] += size[rx];
        }

        return true;
    };

    int res = 0;
    for (const auto& edge : edges) {
        int x = edge[0], y = edge[1], c = edge[2];
        if (merge(x, y)) res += c;
    }

    return res;
}

int main()
{
    vector<vector<int>> points1 {{0,0},{2,2},{3,10},{5,2},{7,0}};
    cout << min_cost_connect_points(points1) << endl;

    vector<vector<int>> points2 {{3,12},{-2,5},{-4,1}};
    cout << min_cost_connect_points(points2) << endl;

    vector<vector<int>> points3 {{0,0},{1,1},{1,0},{-1,1}};
    cout << min_cost_connect_points(points3) << endl;

    vector<vector<int>> points4 {{0,0}};
    cout << min_cost_connect_points(points4) << endl;

    return 0;
}

