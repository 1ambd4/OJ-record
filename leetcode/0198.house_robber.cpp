#include <iostream>
#include <vector>

using namespace std;

// dp[i]: 到第i号房间为止，可偷得的最高金额

int rob(vector<int>& nums)
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

