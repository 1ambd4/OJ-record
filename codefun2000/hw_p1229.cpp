#include <iostream>
#include <vector>
#include <cstdio>
#include <queue>
#include <algorithm>


// 这不就是一拓扑排序板子题么?
// 可以拓扑排序必然无环，扩散的时候用BFS就可以得到结果了
int main()
{
#ifdef LOCAL
    freopen("hw_p1229.in", "r", stdin);
#endif
    int n = 0, t = 0;
    while (std::cin >> n) {
        std::vector<int> in(n+1, 0);
        std::vector<std::vector<int>> edges(n+1, std::vector<int>());
        for (int i = 1; i <= n; ++i) {
            std::cin >> t;
            in[i] = t;

            int u = 0, v = 0;
            for (int j = 0; j < t; ++j) {
                // u -> i
                std::cin >> u;
                edges[u].push_back(i);
            }
        }

        std::queue<int> q, r;
        for (int i = 1; i <= n; ++i) {
            if (in[i] == 0) q.push(i);
        }

        int cnt = 0;
        while (!q.empty()) {
            int s = q.size();
            for (int i = 0; i < s; ++i) {
                int u = q.front();
                q.pop();

                for (const auto& v : edges[u]) {
                    --in[v];
                    if (in[v] == 0) q.push(v);
                }

                r.push(u);
            }
            ++cnt;
        }

        if (r.size() == n) std::cout << cnt << std::endl;
        else std::cout << -1 << std::endl;
    }

    return 0;
}

