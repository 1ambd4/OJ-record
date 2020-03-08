#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

int length_of_LIS(vector<int>& nums) {
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
    assert(length_of_LIS(nums_case1) == 4);

    vector<int> nums_case2 {};
    assert(length_of_LIS(nums_case2) == 0);

    cout << "Accepted by the test example!" << endl;
    return 0;
}