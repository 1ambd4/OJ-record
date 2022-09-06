#include <iostream>
#include <vector>
#include <algorithm>

#include "leetcode.h"

using namespace std;

vector<bool> check_arithmetic_ubarrays(vector<int>& nums, vector<int>& l, vector<int>& r)
{
    int n = l.size();
    vector<bool> res;
    res.reserve(n);

    auto check = [](vector<int> nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), delta = nums[1] - nums[0];
        for (int i = 2; i < n; ++i) {
            if (nums[i] - nums[i-1] != delta) {
                return false;
            }
        }
        return true;
    };

    for (int i = 0; i < n; ++i) {
        if (check(vector<int>(nums.begin()+l[i], nums.begin()+r[i]+1))) {
            res.push_back(true);
        } else {
            res.push_back(false);
        }
    }

    return res;
}

int main()
{
    vector<int> nums1 { 4, 6, 5, 9, 3, 7 };
    vector<int> l1 { 0, 0, 2 }, r1 { 2, 3, 5 };
    vector<bool> res1 = check_arithmetic_ubarrays(nums1, l1, r1);
    cout << res1 << endl;

    return 0;
}
