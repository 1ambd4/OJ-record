#include <iostream>
#include <vector>
#include <algorithm>

#include "leetcode.h"

using namespace std;

// 二分查找，若结果不唯一，返回最右索引
int binary_search(vector<int>& nums, int target)
{
    int left = 0, right = nums.size() - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (nums[mid] == target) {
            // 找到的时候不直接返回，而是收束左边界
            left = mid + 1;
        } else if (nums[mid] > target) {
            right = mid - 1;
        } else if (nums[mid] < target) {
            left = mid + 1;
        }
    }

    if (right < 0 || nums[right] != target) {
        return -1;
    }
    return right;
}

vector<vector<int>> three_sum(vector<int>& nums)
{
    vector<vector<int>> res;

    sort(nums.begin(), nums.end());

    for (int i = 0; i < nums.size(); ++i) {
        for (int j = i + 1; j < nums.size(); ++j) {
            int index = binary_search(nums, 0 - nums[i] - nums[j]);
            if (index != -1 && index > j) {
                res.push_back(vector<int> {nums[i], nums[j], nums[index]}); 
            }
            while (j+1 < nums.size() && nums[j] == nums[j+1]) {
                ++j;
            }
        }
        while (i+1 < nums.size() && nums[i] == nums[i+1]) {
            ++i;
        }
    }

    return res;
}

int main()
{
    vector<int> vec1 { -1, 0, 1, 2, -1, -4 };
    vector<vector<int>> res1 = three_sum(vec1);
    cout << res1 << endl;
    
    vector<int> vec2 { 0, 0, 0, 0 };
    vector<vector<int>> res2 = three_sum(vec2);
    cout << res2 << endl;
    return 0;
}
