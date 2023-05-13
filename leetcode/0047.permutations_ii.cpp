#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>

std::vector<std::vector<int>> permute_unique(std::vector<int>& nums)
{
    int n = nums.size();
    std::vector<std::vector<int>> res;
    std::vector<int> track;
    std::vector<bool> use(n, false);


    if (n == 0) return res;

    auto backtracking = [&res, &nums, &track, &use, &n](auto&& self) -> void {
        if (track.size() == n) {
            res.push_back(track);
            return ;
        }

        for (int i {0}; i < n; ++i) {
            if (i > 0 && nums[i] == nums[i-1] && use[i-1] == false) continue;
            if (use[i] == true) continue;

            use[i] = true;
            track.push_back(nums[i]);
            self(self);
            track.pop_back();
            use[i] = false;
        }
    };

    std::sort(nums.begin(), nums.end());

    backtracking(backtracking);

    return res;
}

int main()
{
#ifdef LOCAL
    freopen("0047.in", "r", stdin);
#endif

    int n = 0;
    while (std::cin >> n) {
        std::vector<int> v(n, 0);
        for (int i{0}; i < n; ++i) std::cin >> v[i];
        std::vector<std::vector<int>> res = permute_unique(v);

        for (const auto& re : res) {
            for (const auto& e : re) {
                std::cout << e << " ";
            }
            std::cout << std::endl;
        }
    }

    return 0;
}

