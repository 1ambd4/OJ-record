#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

std::vector<std::vector<int>> combination_sum2(std::vector<int>& cands, int t)
{
    std::vector<std::vector<int>> res;
    std::vector<int> track;
    std::vector<bool> use(cands.size(), false);

    std::sort(cands.begin(), cands.end(), std::less<int>());

    auto backtracking = [&res, &track, &cands, &use](auto&& self, int s, int t, int k) -> void {
        if (s == t) {
            res.push_back(track);
            return ;
        }

        if (s > t) return ;

        for (int i = k; i < cands.size(); ++i) {
            // 注意这里去重操作
            if (i > 0 && cands[i] == cands[i-1] && use[i-1] == false) continue;
            use[i] = true;
            track.push_back(cands[i]);
            s += cands[i];
            self(self, s, t, i+1);
            s -= cands[i];
            track.pop_back();
            use[i] = false;
        }

    };

    backtracking(backtracking, 0, t, 0);

    return res;
}

int main()
{
#ifdef LOCAL
    freopen("0040.in", "r", stdin);
#endif
    int n = 0, t = 0;
    while (std::cin >> n >> t) {
        std::vector<int> v(n, 0);
        for (int i = 0; i < n; ++i) std::cin >> v[i];
        std::vector<std::vector<int>> res = combination_sum2(v, t);

        for (const auto& re : res) {
            for (const auto& e : re) {
                std::cout << e << " ";
            }
            std::cout << std::endl;
        }
    }
    return 0;
}

