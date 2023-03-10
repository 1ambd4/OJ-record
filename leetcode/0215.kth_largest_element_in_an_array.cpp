#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int find_kth_largest(vector<int>& nums, int k)
{
    priority_queue<int, vector<int>, greater<int>> pq;

    for (const auto& num : nums) {
        pq.push(num);
        if (pq.size() > k) pq.pop();
    }

    return pq.top();
}

int main()
{
    vector<int> nums1 {3,2,1,5,6,4};
    cout << find_kth_largest(nums1, 2) << endl;

    vector<int> nums2 {3,2,3,1,2,4,5,5,6};
    cout << find_kth_largest(nums2, 4) << endl;

    return 0;
}
