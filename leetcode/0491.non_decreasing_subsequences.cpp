#include <iostream>
#include <vector>
#include <cstdio>
#include <unordered_set>

std::vector<std::vector<int>> find_subsequence(std::vector<int>& nums)
{
    std::vector<std::vector<int>> res;
    std::vector<int> track;
    int n = nums.size();

    auto backtracking = [&res, &track, &nums, n](auto&& self, int k) -> void {
        if (track.size() > 1) res.push_back(track);

        std::unordered_set<int> s;

        for (int i {k}; i < n; ++i) {
            if ((!track.empty() && nums[i] < track.back())
                    || (s.find(nums[i]) != s.end()))
                continue;

            s.insert(nums[i]);
            track.push_back(nums[i]);
            self(self, i+1);
            track.pop_back();
        }
    };

    backtracking(backtracking, 0);

    return res;
}

int main()
{
#ifdef LOCAL
    freopen("0491.in", "r", stdin);
#endif
    int n = 0;
    while (std::cin >> n) {
        std::vector<int> v(n);
        for (int i {0}; i < n; ++i) std::cin >> v[i];

        std::vector<std::vector<int>> res = find_subsequence(v);

        for (const auto& re : res) {
            for (const auto& e : re) {
                std::cout << e << " ";
            }
            std::cout << std::endl;
        }
    }
    return 0;
}

