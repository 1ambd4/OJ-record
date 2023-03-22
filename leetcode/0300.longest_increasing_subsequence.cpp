#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

// 定义dp[i]表示前i个数字可得到的最长递增子序列的长度
// 那么考虑dp[i]可能转移来的路径
// 会发现，可以从dp[0]、dp[1] ... dp[i-1]转移来
// 那么此时就考虑for 0...j了（j < i
// 当nums[i]比nums[j]大的时候，就可以选择是否选择从j转移过来
// 体现在代码上就是取一个最大值
int length_of_LIS(vector<int>& nums)
{
    int n = nums.size(), res = 0;
    vector<int> dp(n, 1);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (nums[i] > nums[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        res = max(res, dp[i]);
    }

    return res;
}

int _length_of_LIS(vector<int>& nums) {
    vector<int> dp(nums.size(), 1);

    for (int i = 0; i < nums.size(); ++i) {
        for (int j = 0; j < i; ++j) {
            if (nums[j] < nums[i]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    int result = 0;     // 初始化为0，因为可能传进来一个空串,:'(
    for (int i = 0; i < dp.size(); ++i) {
        result = max(result, dp[i]);
    }

    return result;
}

int main(void) {
    vector<int> nums_case1 {10, 9, 2, 5, 3, 7, 101, 18};
    cout << length_of_LIS(nums_case1) << endl;

    vector<int> nums_case2 {};
    cout << length_of_LIS(nums_case2) << endl;

    return 0;
}
