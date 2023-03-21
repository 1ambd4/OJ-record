#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

int max_subarray(vector<int>& nums)
{
    int n = nums.size(), res = nums[0];
    vector<int> dp(n, 0);

    dp[0] = nums[0];
    for (int i = 1; i < n; ++i) {
        dp[i] = max(dp[i-1] + nums[i], nums[i]);
        res = max(res, dp[i]);
    }

    return res;
}

int _max_subarray(vector<int>& nums) {
    int n = nums.size(), res = nums[0];

    vector<int> f(n, 0);
    f[0] = nums[0];

    for (int i = 1; i < n; ++i) {
        f[i] = max(nums[i], f[i-1] + nums[i]);
        res = max(res, f[i]);
    }

    return res;
}

int main(void) {
    vector<int> nums1 { -2, 1, -3, 4, -1, 2, 1, -5 };
    cout << max_subarray(nums1) << endl;

    vector<int> nums3 { 1, -1, -2 };
    cout << max_subarray(nums3) << endl;

    vector<int> nums2 { 5, 4 -1, 7, 8 };
    cout << max_subarray(nums2) << endl;

    return 0;
}
