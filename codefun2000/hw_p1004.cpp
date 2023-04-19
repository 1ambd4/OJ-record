#include <iostream>
#include <vector>
#include <cstdio>

//  bfs TLE
// int main()
// {
// #ifdef LOCAL
//     freopen("./hw_p1004.in", "r", stdin);
// #endif
//     int n;
//     while (std::cin >> n) {
//         int sum = 0, res = 0;
//         std::vector<int> v(n);
//
//         for (int i = 0; i < n; ++i) {
//             std::cin >> v[i];
//             sum += v[i];
//         }
//
//         auto dfs = [&v, &res](auto&& self, int sum, int k) -> void {
//             if (sum == 0) {
//                 ++res;
//                 return ;
//             }
//
//             if (sum < 0) return ;
//
//             for (int i{k}; i < v.size(); ++i) {
//                 sum -= v[i];
//                 self(self, sum, i+1);
//                 sum += v[i];
//             }
//         };
//
//         if (sum % 2 != 0) std::cout << 0 << std::endl;
//         else {
//             dfs(dfs, sum/2, 0);
//             std::cout << res << std::endl;
//         }
//     }
//
//     return 0;
// }


int main()
{
#ifdef LOCAL
    freopen("./hw_p1004.in", "r", stdin);
#endif
    int n;
    while (std::cin >> n) {
        std::vector<int> v(n+1);
        int sum = 0;

        for (int i = 1; i <= n; ++i) {
            std::cin >> v[i];
            sum += v[i];
        }

        if (sum & 1) std::cout << 0 << std::endl;
        else {
            std::vector<int> dp(1e5+10l);
            dp[0] = 1;
            for (int i = 1; i <= n; ++i) {
                for (int j = sum; j >= v[i]; --j) {
                    dp[j] += dp[j-v[i]];
                }
            }
            std::cout << dp[sum/2] << std::endl;
        }
    }

    return 0;
}
