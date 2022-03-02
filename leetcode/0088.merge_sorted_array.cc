#include <iostream>
#include <vector>

using namespace std;

// 这不就是插入排序么，奇奇怪怪的
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
{
    // 正向遍历的坏处就是需要处理nums1为空的情况
    if (m == 0) {
        for (int i = 0; i < n; ++i) {
            nums1[i] = nums2[i];
        }
    }
    
    for (int i = 0, j = 0; i < n; ++i) {
        for ( ; j < m; ++j) {
            if (nums2[i] < nums1[j]) {
                for (int k = m; k > j; --k) {
                    nums1[k] = nums1[k-1];
                }
                nums1[j] = nums2[i];
                ++m;
                break;
            }
            if (j == m-1) {
                nums1[m++] = nums2[i];
                break;
            }
        }
    }
}

int main()
{
    vector<int> nums1 = { 1, 2, 3, 0, 0, 0 };
    vector<int> nums2 = { 2, 5, 6 };
    merge(nums1, 3, nums2, 3);
    for (const int& num : nums1) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}
