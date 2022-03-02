#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

int max_subarray(vector<int>& nums) {
    int result = nums[0];
    vector<int> dp(nums);
    for (int i = 1; i < nums.size(); ++i) {
        dp[i] = max(nums[i], dp[i-1]+nums[i]);
        result = dp[i] > result ? dp[i] : result;
    }

    return result;
}

int main(void) {
    vector<int> nums_case1 { -2, 1, -3, 4, -1, 2, 1, -5 };
    assert(max_subarray(nums_case1) == 6);
    
    vector<int> nums_case2 { 5, 4 -1, 7, 8 };
    assert(max_subarray(nums_case2) == 23);
    
    
    cout << "Accepted by the test example!" << endl;

    return 0;
}
