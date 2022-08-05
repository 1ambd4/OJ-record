#include <iostream>
#include <vector>

using namespace std;

bool can_partition(vector<int>& nums)
{
    int sum = 0;
    for (const auto& num : nums) {
        sum += num;
    }

    if (sum % 2 == 1) {
        return false;
    }

    int w = sum / 2, n = nums.size();
    vector<vector<int>> dp(n + 1, vector<int>(w+1, 0));

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= w; ++j) {
            if (j - nums[i-1] < 0) {
                dp[i][j] = dp[i-1][j];
            } else {
                dp[i][j] = max(dp[i-1][j-nums[i-1]] + nums[i-1], dp[i-1][j]);
            }
        }
    }

    return dp[n][w] == w;
}

int main()
{
    vector<int> nums1 { 1, 5, 11, 5 };
    cout << can_partition(nums1) << endl;

    vector<int> nums2 { 1, 2, 3, 5 };
    cout << can_partition(nums2) << endl;
    return 0;
}

