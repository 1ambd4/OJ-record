#include <iostream>
#include <vector>

#include "leetcode.h"

using namespace std;

void move_zeroes(vector<int>& nums)
{
    int left = 0, right = 0;
    while (right < nums.size()) {
        if (nums[right]) {
            swap(nums[left++], nums[right]);
        }
        ++right;
    }
}


// 快慢指针，i指向0串首，j向后找非零元素，找到就交换数据
void move_zeroes_(vector<int>& nums)
{
    int n = nums.size();
    for (int i = 0; i < n; ++i) {
        if (nums[i] != 0) {
            continue;
        }
        // 这时候i指向第一个0
        for (int j = i; j < n; ++j) {
            if (nums[j] != 0) {
                swap(nums[i], nums[j]);
                break;
            }
        }
    }
}

// 要保持非零数字原顺序啊，看差了
void move_zeroes__(vector<int>& nums)
{
    int n = nums.size();
    int l = 0, r = n - 1;

    while (l < r) {
        if (nums[l] == 0) {
            while (nums[r] == 0) --r;
            swap(nums[l], nums[r]);
            ++l, --r;
        } else {
            ++l;
        }
    }
}

void _move_zeroes(vector<int>& nums)
{
    int n = nums.size();
    int l = 0, r = 0;

    while (r < n) {
        if (nums[r]) {
            swap(nums[l++], nums[r]);
        }
        ++r;
    }
}

int main()
{
    vector<int> case1 { 0, 1, 0, 3, 12 };
    move_zeroes(case1);
    print_vector(case1);

    vector<int> case2 { 0, 0, 1, 3, 12 };
    move_zeroes(case2);
    print_vector(case2);

    return 0;
}
