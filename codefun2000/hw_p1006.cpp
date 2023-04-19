#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>


// 没啥思路只能暴力了，稍微优化下用二分
// int main()
// {
// #ifdef LOCAL
//     freopen("./hw_p1006.in", "r", stdin);
// #endif
//     int n = 0, tot = 0;
//     while (std::cin >> n >> tot) {
//         std::vector<int> v(n);
//         int sum = 0, mxn = 0;
//         for (int i = 0; i < n; ++i) {
//             std::cin >> v[i];
//             sum += v[i];
//             mxn = std::max(mxn, v[i]);
//         }
//         auto check = [&v](int x, int tot) -> bool {
//             int n = v.size(), sum = 0;
//             for (int i = 0; i < n; ++i) {
//                 sum += std::min(x, v[i]);
//             }
//             return sum <= tot;
//         };
//         if (sum < tot) {
//             std::cout << -1 << std::endl;
//         } else {
//             // 得从0开始，因为有可能任何一个数字都大于tot，这时候只能全部置0
//             int l = 0, r = mxn;
//             while (l < r) {
//                 int m = l + r + 1 >> 1;
//                 if (check(m, tot)) l = m;
//                 else r = m - 1;
//             }
//             std::cout << l << std::endl;
//         }
//     }
//
//     return 0;
// }


// 比minx小的是不会被替换的，因而从tot里减去
// 而剩下的那些都该被替换掉，且它们的总和不能超过tot的当前值，故而tot/size。
int main()
{
#ifdef LOCAL
    freopen("./hw_p1006.in", "r", stdin);
#endif
    int n = 0, tot = 0;
    while (std::cin >> n >> tot) {
        int sum = 0;
        std::vector<int> v(n);
        for (int i = 0; i < n; ++i) {
            std::cin >> v[i];
            sum += v[i];
        }

        if (sum < tot) std::cout << -1 << std::endl;
        else {
            int size = n;
            int minx = tot / size;
            for (auto x : v) {
                if (x <= minx) {
                    --size;
                    tot -= x;
                }
            }
            std::cout << (int)(tot / size) << std::endl;
        }
    }

    return 0;
}
