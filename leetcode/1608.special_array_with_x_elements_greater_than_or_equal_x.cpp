#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int binary_search(vector<int>& nums, int value)
{
    int l = 0, r = nums.size() - 1;

    while (l < r) {
        int m = l + r >> 1;
        if (nums[m] >= value) r = m;
        else l = m + 1;
    }

    return l;
}

int special_array_(vector<int>& nums)
{
    sort(nums.begin(), nums.end());
    int n = nums.size();
    for (int i = 0; i <= n; ++i) {
        int idx = binary_search(nums, i);
        if (nums[idx] >= i && i == n - idx) {
            return i;
        }
    }

    return -1;
}

int special_array(vector<int>& nums)
{
    sort(nums.begin(), nums.end());
    int n = nums.size();

    for (int i = 0; i <= n; ++i) {
        if (i == n - (lower_bound(nums.begin(), nums.end(), i) - nums.begin())) {
            return i;
        }
    }

    return -1;
}

int main()
{
    vector<int> nums1 { 3, 5 };
    cout << special_array_(nums1) << endl;

    vector<int> nums2 { 0, 0 };
    cout << special_array_(nums2) << endl;
    return 0;
}
