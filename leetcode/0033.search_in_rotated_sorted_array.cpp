#include <iostream>
#include <vector>
#include <cstdio>

// 将数组一分为二的情况下，定然有一边是有序的，另一半可能有序
// 那么，将无序部分继续二分，又可以分成一个有序和可能有序的部分
// 一直继续下去
int search(std::vector<int>& nums, int target)
{
    int n = nums.size();
    if (n == 0) return -1;
    if (n == 1) return nums[0] == target ? 0 : -1;

    int l = 0, r = n - 1;
    while (l <= r) {
        int m = (l + r) >> 1;
        if (nums[m] == target) return m;
        if (nums[0] <= nums[m]) {
            if (nums[0] <= target && target < nums[m]) {
                r = m - 1;
            } else {
                l = m + 1;
            }
        } else {
            if (nums[m] < target && target <= nums[n-1]) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
    }

    return -1;
}


// int search(std::vector<int>& nums, int target)
// {
//     int res = -1;
//     int left = 0, right = nums.size() - 1;
//
//     auto binary_search = [&nums](int l, int r, int t) -> int {
//         while (l < r) {
//             int m = (l + r) >> 1;
//             if (nums[m] >= t) r = m;
//             else l = m + 1;
//         }
//         return l;
//     };
//
//     // 大概有三种情况，正序、旋转有序
//     if (nums[left] < nums[right]) {
//         res = binary_search(left, right, target);
//     }
//     return res;
// }


int main()
{
#ifdef LOCAL
    freopen("0033.in", "r", stdin);
#endif
    int n = 0, t = 0, a = 0;
    while (std::cin >> n) {
        std::vector<int> nums(n, 0);
        for (int i = 0; i < n; ++i) {
            std::cin >> a;
            nums[i] = a;
        }
        std::cin >> t;
        std::cout << search(nums, t) << std::endl;
    }

    return 0;
}
