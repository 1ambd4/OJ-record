#include <iostream>
#include <vector>

using namespace std;

void quick_sort(vector<int>& q, int l, int r)
{
    if (l >= r) return ;

    int x = q[l], i = l - 1, j = r + 1;

    while (i < j) {
        do ++i; while (q[i] < x);
        do --j; while (q[j] > x);
        if (i < j) swap(q[i], q[j]);
    }

    quick_sort(q, l, j);
    quick_sort(q, j+1, r);
}

bool can_make_arithmethc_progression(vector<int>& nums)
{
    int n = nums.size();
    quick_sort(nums, 0, n-1);

    for (int i = 2, t = nums[1] - nums[0]; i < n; ++i) {
        if (nums[i] - nums[i-1] != t) return false;
    }

    return true;
}

int main()
{
    vector<int> nums1 { 3, 5, 1 };
    cout << can_make_arithmethc_progression(nums1) << endl;

    vector<int> nums2 { 1, 2, 4 };
    cout << can_make_arithmethc_progression(nums2) << endl;
    return 0;
}

