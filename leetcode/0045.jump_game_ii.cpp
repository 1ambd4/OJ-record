#include <iostream>
#include <vector>
#include <limits>

using namespace std;

// 动态规划比贪心慢多了
// 因为动态规划就是优化后的暴力搜索（广度优先遍历）
// 而且这题比较奇怪，很难做剪枝，使得多了很多重复计算

// 动态规划，正向遍历
int jump(vector<int>& nums)
{
    int n = nums.size();
    vector<int> dp(n, numeric_limits<int>::max() >> 1);

    dp[0] = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i; j <= i + nums[i] && j < n; ++j) {
            dp[j] = min(dp[i] + 1, dp[j]);
        }
    }

    return dp[n-1];
}

// 动态规划，反向遍历
int _jump(vector<int>& nums)
{
    int n = nums.size();
    vector<int> dp(n, numeric_limits<int>::max() >> 1);

    dp[n-1] = 0;
    for (int i = n - 2; i >= 0; --i) {
        if (nums[i] >= n - 1 - i) {
            dp[i] = 1;
            continue;
        }
        for (int j = i + nums[i]; j > i; --j) {
            dp[i] = min(dp[i], 1 + dp[j]);
        }
    }

    return dp[0];
}

int __jump(vector<int>& nums)
{
    int n = nums.size(), res = 0;

    // 因为题目已经确定了必然可以到达终点
    // 因而可以采用贪心的思想
    // 每次都在可跳跃范围内选择可以跳到最远的点
    // 同时，最后一个点也无需考虑
    // 因为最坏的情况是刚好到倒数第二个点，此时是会将计数加1的
    // 由于比较可以到达终点的限制在，在倒数第二个点上必然可以跳到终点
    for (int i = 0, cur = 0, dis = 0; i < n - 1; ++i) {
        dis = max(dis, i + nums[i]);
        if (cur == i) {
            ++res;
            cur = dis;
        }
    }

    return res;
}

int main()
{
    vector<int> nums1 {2,3,1,1,4};
    cout << jump(nums1) << endl;

    vector<int> nums2 {2,3,0,1,4};
    cout << jump(nums2) << endl;

    return 0;
}

