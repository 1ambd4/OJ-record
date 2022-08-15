#include <iostream>
#include <vector>

#include "leetcode.h"

using namespace std;

void quick_sort(vector<int>& q, int l, int r)
{
    if (l >= r) return ;

    int x = q[l], i = l-1, j = r+1;

    while (i < j) {
        do ++i; while (q[i] > x);
        do --j; while (q[j] < x);
        if (i < j) swap(q[i], q[j]);
    }

    quick_sort(q, l, j);
    quick_sort(q, j+1, r);
}

// easy题不easy
int largest_perimeter(vector<int>& nums)
{
    int n = nums.size();

    quick_sort(nums, 0, n-1);

    for (int i = 0; i < n - 2; ++i) {
        int a = nums[i], b = nums[i+1], c = nums[i+2];
        if (a < b + c) {
            return a + b + c;
        }
    }

    return 0;
}

int main()
{
    vector<int> nums1 { 2, 1, 2 };
    cout << largest_perimeter(nums1) << endl;

    vector<int> nums2 { 1, 2, 1 };
    cout << largest_perimeter(nums2) << endl;
    return 0;
}
