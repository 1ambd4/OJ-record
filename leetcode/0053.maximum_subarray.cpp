#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

int max_subarray(vector<int>& nums) {
    vector<int> dp (nums);
    int result = dp[0];

    for (int i = 1; i < nums.size(); ++i) {
       dp[i] = max(dp[i], dp[i-1]+nums[i]);
       if (dp[i] > result) result = dp[i];
    }

    return result;
}

int main(void) {
    vector<int> nums_case1 {-2, 1, -3, 4, -1, 2, 1, -5};
    assert(max_subarray(nums_case1) == 6);

    cout << "Accepted by the test example!" << endl;

    return 0;
}