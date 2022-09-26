#include <iostream>
#include <vector>

#include "leetcode.h"

using namespace std;

vector<int> missing_two(vector<int>& nums)
{
    nums.push_back(-1);
    nums.push_back(-1);

    int n = nums.size();

    for (int i = 0; i < n; ++i) {
        while (nums[i] != -1 && nums[i] != i + 1) {
            swap(nums[i], nums[nums[i]-1]);
        }
    }

    vector<int> ans;
    for (int i = 0; i < n; ++i) {
        if (nums[i] == -1) ans.push_back(i+1);
    }

    return ans;
}

int main()
{
    vector<int> nums1 { 1 };
    cout << missing_two(nums1) << endl;

    vector<int> nums2 { 2, 3 };
    cout << missing_two(nums2) << endl;

    return 0;
}

