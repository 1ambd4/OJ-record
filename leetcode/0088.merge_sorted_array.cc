#include <iostream>
#include <vector>

using namespace std;

// 正向遍历是插入排序，反向遍历就变成了归并排序
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
{
    int tail = nums1.size() - 1;
    --m, --n;
    while (n >= 0) {
        while (m >= 0 && nums1[m] > nums2[n]) {
            swap(nums1[tail--], nums1[m--]);
        }
        swap(nums1[tail--], nums2[n--]);
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
