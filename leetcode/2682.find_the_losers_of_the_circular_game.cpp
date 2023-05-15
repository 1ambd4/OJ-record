#include <iostream>
#include <vector>
#include <cstdio>

std::vector<int> circular_game_losers(int n, int k)
{
    std::vector<int> res;
    std::vector<int> vis(n, 0);

    vis[0] = 1;

    int id = 0;
    for (int i{1}; ; ++i) {
        id = (id + i * k) % n;
        ++vis[id];
        if (vis[id] == 2) break;
    }

    for (int i = 0; i < n; ++i) {
        if (vis[i] == 0) res.push_back(i+1);
    }

    return res;
}

int main()
{
#ifdef LOCAL
    freopen("2682.in", "r", stdin);
#endif

    int n = 0, k = 0;
    while (std::cin >> n >> k) {
        std::vector<int> res = circular_game_losers(n, k);
        for (const auto& e : res) std::cout << e << " ";
        std::cout << std::endl;
    }

    return 0;
}

