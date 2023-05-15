#include <iostream>
#include <vector>
#include <cstdio>
#include <unordered_map>

int count_complete_components(int n, std::vector<std::vector<int>>& edges)
{
    int res = 0;

    std::vector<int> pa(n);
    // gh临接矩阵，以待最后查询完全联通分量用
    std::vector<std::vector<int>> gh(n, std::vector<int>(n, 0));
    for (int i{0}; i < n; ++i) pa[i] = i;

    auto fund = [&pa](auto&& self, int x) -> int {
        // if (pa[x] == x) return x;
        // else return self(self, pa[x]);
        return x == pa[x] ? x : (pa[x] = self(self, pa[x]));
    };

    auto unon = [&pa, fund](int x, int y) -> void {
        if (x > y) std::swap(x, y);

        int rx = fund(fund, x), ry = fund(fund, y);
        if (rx == ry) return ;

        pa[ry] = pa[rx];
    };

    for (const auto& edge : edges) {
        int x = edge[0], y = edge[1];
        gh[x][y] = gh[y][x] = 1;
        unon(x, y);
    }

    // for (int i = 0; i < n; ++i) {
    //     if (pa[i] == i) ++res;
    // }

    std::unordered_map<int, std::vector<int>> gp;
    for (int i = 0; i < n; ++i) {
        gp[fund(fund, i)].push_back(i);
    }
    auto check = [&gh](std::vector<int>& v) -> bool {
        int m = v.size();
        for (int i = 0; i < m; ++i) {
            for (int j = i+1; j < m; ++j) {
                if (!gh[v[i]][v[j]]) return false;
            }
        }
        return true;
    };

    for (auto& [id, ps]: gp) {
        if (check(ps)) ++ res;
    }

    return res;
}

int main()
{
#ifdef LOCAL
    freopen("2685.in", "r", stdin);
#endif

    std::vector<std::vector<int>> edges1{{0,1}, {0,2}, {1,2}, {3,4}};
    std::cout << count_complete_components(6, edges1) << std::endl;

    std::vector<std::vector<int>> edges2{{0,1}, {0,2}, {1,2}, {3,4}, {3,5}};
    std::cout << count_complete_components(6, edges2) << std::endl;

    return 0;
}

