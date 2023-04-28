#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <set>

// 原地哈希
int first_missing_positive(std::vector<int>& nums)
{
    int n = nums.size();

    // 构造hash(i) = i - 1
    // 即使用原数组，将每个正整数映射到正确的位置上
    // 则第一个不满足nums[i] = i + 1条件的数字即为缺失值
    for (int i = 0; i < n; ++i) {
        while (nums[i] > 0 && nums[i] <= n && nums[nums[i]-1] != nums[i]) {
            std::swap(nums[nums[i]-1], nums[i]);
        }
    }

    for (int i = 0; i < n; ++i) {
        if (nums[i] != i + 1) {
            return i + 1;
        }
    }

    return n + 1;
}

int _first_missing_positive(std::vector<int>& nums)
{
    std::set s(nums.begin(), nums.end());

    // 不晓得为啥vector去重会报heap-buffer-overflow
    // std::sort(nums.begin(), nums.end(), std::less<int>());
    // auto last = std::unique(nums.begin(), nums.end());
    // nums.erase(last, nums.begin());

    int res = 1;
    for (const auto& num : s) {
        if (num < 1) continue;
        if (num == res) ++res;
        else {
            return res;
        }
    }
    return res;
}

int main()
{
#ifdef LOCAL
    freopen("0041.in", "r", stdin);
#endif
    int n = 0;
    while (std::cin >> n) {
        std::vector<int> nums(n);
        for (int i = 0; i < n; ++i) std::cin >> nums[i];
        std::cout << first_missing_positive(nums) << std::endl;
    }

    return 0;
}
