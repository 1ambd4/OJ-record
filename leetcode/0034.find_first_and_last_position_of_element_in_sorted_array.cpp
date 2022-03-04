#include <iostream>
#include <vector>

#include "leetcode.h"

using namespace std;

int lower_bound(vector<int> &nums, int target)
{
    int left = 0, right = nums.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target) {
            right = mid -1;
        } else if (nums[mid] < target) {
            left = mid + 1;
        } else if (nums[mid] > target) {
            right = mid -1;
        }
    }

    // 排除target比所有元素都大以及不存在target的情况
    if (left >= nums.size() || nums[left] != target) {
        return -1;
    }
    return left;
}

int upper_bound(vector<int> &nums, int target)
{
    int left = 0, right = nums.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target) {
            left = mid + 1;
        } else if (nums[mid] < target) {
            left = mid + 1;
        } else if (nums[mid] > target) {
            right = mid - 1;
        }
    }

    // 排除掉target比所有元素都小以及不存在target的情况
    if (right < 0 || nums[right] != target) {
        return -1;
    }
    return right;
}

vector<int> search_range(vector<int> &nums, int target)
{
    int left = lower_bound(nums, target);
    int right = upper_bound(nums, target);

    return {left, right};
}

int main()
{
    vector<int> nums1 {5,7,7,8,8,10};
    vector<int> res1 = search_range(nums1, 8);
    print_vector(res1);


    vector<int> nums2 {5,7,7,8,8,10};
    vector<int> res2 = search_range(nums2, 6);
    print_vector(res2);
    return 0;
}
