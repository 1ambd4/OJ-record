#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>


struct line {
public:
    int o, r, v;
};

bool operator < (const line& a, const line& b)
{
    return a.o < b.o;
};


// 有些像最长上升子序列，那么同样定义dp[i]为以i结尾的线段的最大价值
int main()
{
#ifdef LOCAL
    freopen("./hw_p1019.in", "r", stdin);
#endif

    int n = 0;
    while (std::cin >> n) {
        std::vector<line> v(n);
        int ans = 0;

        for (int i = 0; i < n; ++i) std::cin >> v[i].o;
        for (int i = 0; i < n; ++i) std::cin >> v[i].r;
        for (int i = 0; i < n; ++i) std::cin >> v[i].v;

        std::sort(v.begin(), v.end());

        std::vector<int> dp(n);
        for (int i = 0; i < n; ++i) dp[i] = v[i].v;
        // 这里i不能从1开始，因为把更新ans的逻辑写在for里了
        // 试想如果只有一条线段，那从1开始的话，for循环都进不去
        // 更别谈更新ans了，因而要么把ans初始为v[0].v，要么从0开始
        // 显然从0开始写起来更优雅些
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (v[i].o - v[i].r >= v[j].o + v[j].r) {
                    dp[i] = std::max(dp[i], dp[j] + v[i].v);
                }
            }
            ans = std::max(ans, dp[i]);
        }

        std::cout << ans << std::endl;
    }

    return 0;
}

