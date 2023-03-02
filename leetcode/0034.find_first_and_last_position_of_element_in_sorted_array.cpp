#include <iostream>
#include <vector>

#include "leetcode.h"

using namespace std;

// left bound
int lower_bound(vector<int> &nums, int target)
{
    int l = 0, r = nums.size() - 1;
    while (l < r) {
        int m = (l + r) >> 1;
        if (nums[m] >= target) r = m;
        else l = m + 1;
    }

    return nums[l] != target ? -1 : l;
}

// right bound
int upper_bound(vector<int> &nums, int target)
{
    int l = 0, r = nums.size() - 1;
    while (l < r) {
        int m = (l + r + 1) >> 1;
        if (nums[m] <= target) l = m;
        else r = m - 1;
    }

    return nums[l] != target ? -1 : l;
}


vector<int> search_range(vector<int> &nums, int target)
{
    if (nums.size() == 0) return {-1, -1};

    int left = lower_bound(nums, target);
    int right = upper_bound(nums, target);

    return {left, right};
}


int _lower_bound(vector<int> &nums, int target)
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

int _upper_bound(vector<int> &nums, int target)
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


int main()
{
    vector<int> nums1 {5,7,7,8,8,10};
    vector<int> res1 = search_range(nums1, 8);
    print_vector(res1);


    vector<int> nums2 {5,7,7,8,8,10};
    vector<int> res2 = search_range(nums2, 6);
    print_vector(res2);

    vector<int> nums3 {};
    vector<int> res3 = search_range(nums3, 0);
    print_vector(res3);

    return 0;
}
