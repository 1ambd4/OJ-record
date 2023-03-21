#include <iostream>
#include <vector>

using namespace std;

int rob(vector<int>& nums)
{
    int n = nums.size();
    if (n == 1) return nums[0];

    vector<int> dp(n, -1);
    dp[0] = nums[0], dp[1] = max(nums[0], nums[1]);
    for (int i = 2; i < n; ++i) {
        dp[i] = max(dp[i-1], dp[i-2] + nums[i]);
    }

    return dp[n-1]
}

// 显然f[i][0]和f[i][1]可以优化的
int _rob(vector<int>& nums)
{
    int n = nums.size();

    if (n == 1) return nums[0];
    vector<vector<int>> f(n, vector<int>(2, 0));
    f[0][0] = 0, f[0][1] = nums[0];

    for (int i = 1; i < n; ++i) {
        f[i][0] = max(f[i-1][0], f[i-1][1]);
        f[i][1] = f[i-1][0] + nums[i];
    }

    return max(f[n-1][0], f[n-1][1]);
}


// dp[i]: 到第i号房间为止，可偷得的最高金额
int __rob(vector<int>& nums)
{
    int n = nums.size();

    if (n == 1) return nums[0];

    vector<int> dp(n, -1);
    dp[0] = nums[0], dp[1] = max(nums[0], nums[1]);

    for (int i = 2; i < n; ++i) {
        dp[i] = max(dp[i-1], dp[i-2]+nums[i]);
    }

    return dp[n-1];
}

int main()
{
    vector<int> nums1 { 1, 2, 3, 1 };
    cout << rob(nums1) << endl;

    vector<int> nums2 { 2, 7, 9, 3, 1 };
    cout << rob(nums2) << endl;

    vector<int> nums3 { 0 };
    cout << rob(nums3) << endl;
    return 0;
}

