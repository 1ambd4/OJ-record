#include <iostream>
#include <vector>

using namespace std;

int num_subarray_product_less_than_k(vector<int>& nums, int k)
{
    int n = nums.size();
    int l = 0, r = 0, p = 1;
    int cnt = 0;

    while (r < n) {
        p *= nums[r++];

        while (l < r && p >= k) {
            p /= nums[l++];
        }

        // 窗口内每次最后面增加一个元素
        // 其不重复的子集个数增量为：(1+2+3+...+n) - (1+2+3+...+n-1) = n
        cnt += r - l;
    }

    return cnt;
}

int main()
{
    vector<int> nums1 { 10, 5, 2, 6 };
    cout << num_subarray_product_less_than_k(nums1, 100) << endl;
    return 0;
}

