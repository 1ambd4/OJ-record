#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// 当i～j是一个满足题意的子数组时： k = ps[i] - ps[j]
int subarray_sum(vector<int>& nums, int k)
{
    unordered_map<int, int> ps;
    ps[0] = 1;

    int res = 0, sum = 0;
    for (const auto& num : nums) {
        sum += num;
        res += ps[sum-k];
        ps[sum]++;
    }

    return res;
}


// 内层O(n)的for循环可以使用哈希表优化掉
int _subarray_sum(vector<int> &nums, int k)
{
    unordered_map<int, int> preSum;
    preSum[0] = 1;

    int res = 0, sum = 0;
    for (const auto &num : nums) {
        sum += num;
        res += preSum[sum-k];
        ++preSum[sum];
    }

    return res;
}

// 穷举所有可能的子区间，TLE
int __subarray_sum(vector<int> &nums, int k)
{
    vector<int> preSum(nums.size()+1, 0);
    preSum[0] = 0;
    for (int i = 1; i < preSum.size(); ++i) {
        preSum[i] = preSum[i-1] + nums[i-1];
    }

    int res = 0;
    for (int i = 0; i < preSum.size(); ++i) {
        for (int j = 0; j < i; ++j) {
            if (preSum[i] - k == preSum[j]) {
                res++;
            }
        }
    }

    return res;
}

int main()
{
    vector<int> case1 { 1, 1, 1 };
    cout << subarray_sum(case1, 2) << endl;

    vector<int> case2 { 1, 2, 3 };
    cout << subarray_sum(case2, 3) << endl;
    return 0;
}
