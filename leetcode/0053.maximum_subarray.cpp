#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

int max_subarray(vector<int>& nums) {
    int n = nums.size(), res = nums[0];

    vector<int> f(n, 0);
    f[0] = nums[0];

    for (int i = 1; i < n; ++i) {
        f[i] = max(nums[i], f[i-1] + nums[i]);
        res = max(res, f[i]);
    }

    return res;
}

int main(void) {
    vector<int> nums1 { -2, 1, -3, 4, -1, 2, 1, -5 };
    assert(max_subarray(nums1) == 6);
    
    vector<int> nums2 { 5, 4 -1, 7, 8 };
    assert(max_subarray(nums2) == 23);
    
    vector<int> nums3 { 1, -1, -2 };
    assert(max_subarray(nums3) == 1);
    
    cout << "Accepted by the test example!" << endl;

    return 0;
}
