#include <iostream>
#include <vector>
#include <cstdio>

// 原地哈希
// 添加一个不可能出现的元素后，把数字都映射到对应下标的位置处
// 那么之后就可以扫一遍，来检查哪个位置上的元素不满足条件
// 需要注意的是，引入的元素在交换的过程中，可能会导致错乱的交换
// 故而需要检查的是引入的元素出现在了哪个位置上，以及这个位置上的元素是否出现
// 答案就在这两者之间
int missing_number(std::vector<int>& nums)
{
    nums.push_back(-1);
    int n = nums.size();

    for (int i{0}; i < n; ++i) {
        if (nums[i] == -1) continue;
        std::swap(nums[nums[i]], nums[i]);
    }

    int a = -1, b = -1;
    for (int i{0}; i < n; ++i) {
        if (nums[i] == -1) a = i;
        if (nums[i] != i) b = i;
    }

    return b != -1 ? b : a;
}

// 位运算
int _missing_number(std::vector<int>& nums)
{
    int n = nums.size();
    int res = 0 ^ n;
    for (int i = 0; i < n; ++i) {
        res ^= i;
        res ^= nums[i];
    }

    return res;
}

int main()
{
#ifdef LOCAL
    freopen("0268.in", "r", stdin);
#endif
    int n = 0;
    while (std::cin >> n) {
        std::vector<int> nums(n);
        for (int i = 0; i < n; ++i) std::cin >> nums[i];
        std::cout << missing_number(nums) << std::endl;
    }

    return 0;
}

