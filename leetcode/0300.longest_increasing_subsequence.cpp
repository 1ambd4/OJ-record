#include <iostream>
#include <vector>

using namespace std;

int length_of_lis(vector<int>& nums)
{
    vector<int> dp(nums.size(), 1);

    for (int i = 0; i < nums.size(); ++i) {
        for (int j = 0; j < i; ++j) {
            if (nums[j] < nums[i]) {
                dp[i] = max(dp[i], dp[j]+1);
            }
        }
    }

    int res = 1;
    for (int i = 0; i < dp.size(); ++i) {
        res = max(res, dp[i]);
    }

    return res;
}

int main()
{
    vector<int> nums1 { 10, 9, 2, 5, 3, 7, 101, 18 };
    cout << length_of_lis(nums1) << endl;

    vector<int> nums2 { 0, 1, 0, 3, 2, 3 };
    cout << length_of_lis(nums2) << endl;

    vector<int> nums3 { 7, 7, 7, 7, 7, 7, 7 };
    cout << length_of_lis(nums3) << endl;

    return 0;
}

