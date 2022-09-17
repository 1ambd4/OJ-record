#include <iostream>
#include <vector>

using namespace std;

// just the same as 0198.house-rober?
int delete_and_earn(vector<int>& nums)
{
    int n = nums.size();
    if (n == 1) return nums[0];

    vector<int> arr(1e4 + 10, 0);
    for (const auto num : nums) {
        arr[num] += num;
    }

    vector<int> f(1e4 + 10, 0);
    f[0] = arr[0]; f[1] = max(arr[0], arr[1]);
    for (int i = 2; i < 1e4+10; ++i) {
        f[i] = max(f[i-1], f[i-2] + arr[i]);
    }

    return f[f.size()-1];
}

int main()
{
    vector<int> nums1 { 3, 4, 2 };
    cout << delete_and_earn(nums1) << endl;

    vector<int> nums2 { 2, 2, 3, 3, 3, 4 };
    cout << delete_and_earn(nums2) << endl;
    return 0;
}

