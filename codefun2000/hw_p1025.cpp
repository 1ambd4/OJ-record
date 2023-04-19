#include <iostream>
#include <vector>
#include <cstdio>

struct gun {
public:
    int d, c, t;  // damage cost time
};

// 多重背包
int main()
{
#ifdef LOCAL
    freopen("./hw_p1025.in", "r", stdin);
#endif

    int n = 0, m = 0, t = 0;
    while (std::cin >> n >> m >> t) {
        std::vector<gun> v(n);
        for (int i{0}; i < n; ++i) std::cin >> v[i].d >> v[i].c >> v[i].t;

        std::vector<std::vector<int>> dp(n+1, std::vector<int>(m+1, 0));

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                for (int k = 0; k <= t/v[i-1].t; ++k) {
                    if (j >= k * v[i-1].c) {
                        dp[i][j] = std::max(dp[i][j], dp[i-1][j-k*v[i-1].c] + k*v[i-1].d);
                    }
                }
            }
        }

        std::cout << dp[n][m] << std::endl;
    }

    return 0;
}

