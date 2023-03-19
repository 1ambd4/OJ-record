#include <iostream>
#include <vector>

using namespace std;

bool valid_tree(int n, vector<vector<int>>& edges)
{
    vector<int> parent(n), size(n, 0);
    for (int i = 0; i < n; ++i) parent[i] = i;

    auto find = [&parent](int x) {
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

    for (const auto& edge : edges) {
        if (!merge(edge[0], edge[1]))  return false;
    }

    return true;
}

int main()
{
    vector<vector<int>> edges1 {{0,1},{0,2},{0,3},{1,4}};
    cout << valid_tree(5, edges1) << endl;

    vector<vector<int>> edges2 {{0,1},{1,2},{2,3},{1,3},{1,4}};
    cout << valid_tree(5, edges2) << endl;

    return 0;
}

