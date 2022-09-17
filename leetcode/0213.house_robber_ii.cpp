#include <iostream>
#include <vector>
#include <utility>

using namespace std;

// split the ring into two parts
int rob(vector<int>& nums)
{
    using PII = pair<int, int>;
    int n = nums.size(), res = -1;
    vector<vector<PII>> f(2, vector<PII>(n, {0,0}));

    if (n == 1) return nums[0];
    if (n == 2) return max(nums[0], nums[1]);

    // select house n, don't select house 1
    f[0][0].first = 0; f[0][0].second = 0;
    f[0][1].first = 0; f[0][1].second = nums[1];
    for (int i = 2; i < n; ++i) {
        f[0][i].first = max(f[0][i-1].first, f[0][i-1].second);
        f[0][i].second = f[0][i-1].first + nums[i];
    }
    res = max(f[0][n-1].first, f[0][n-1].second);

    // select house 1, dont't select house n
    f[1][0].first = 0; f[1][0].second = nums[0];
    for (int i = 1; i < n - 1; ++i) {
        f[1][i].first = max(f[1][i-1].first, f[1][i-1].second);
        f[1][i].second = f[1][i-1].first + nums[i];
    }
    res = max(res, f[1][n-2].first);
    res = max(res, f[1][n-2].second);

    return res;
}


int main()
{
    vector<int> nums1 { 2, 3, 2 };
    cout << rob(nums1) << endl;

    vector<int> nums2 { 1, 2, 3, 1 };
    cout << rob(nums2) << endl;

    vector<int> nums3 { 1, 2, 3 };
    cout << rob(nums3) << endl;
    return 0;
}

