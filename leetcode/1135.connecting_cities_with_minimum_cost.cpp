#include <iostream>
#include <vector>
#include <algorithm>

#include "leetcode.h"

using namespace std;

int minimum_cost(int n, vector<vector<int>>& connections) {
    int res = 0;
    vector<int> parent(n), size(n, 0);
    for (int i = 0; i < n; ++i) parent[i] = i;

    sort(connections.begin(), connections.end(), [](vector<int>& a, vector<int>& b) -> bool {
                    return a[2] < b[2];
    });

    auto find = [&parent](int x) {
        while (parent[x] != x) {
            parent[x] = parent[parent[x]];
            x = parent[x];
        }

        return x;
    };

    auto merge = [&parent, &size, &find](int x, int y) -> bool {
        int rx = find(x-1), ry = find(y-1);
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

    for (const auto& connection : connections) {
        int x = connection[0], y = connection[1], c = connection[2];
        if (merge(x, y)) res += c;
    }


    return res;
}

int main()
{
    vector<vector<int>> connections1 {{1,2,5},{1,3,6},{2,3,1}};
    cout << minimum_cost(3, connections1) << endl;
    return 0;
}

