#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// log(m+n)的二分法还没写出来
double find_median_sorted_arrays(vector<int>& nums1, vector<int>& nums2)
{
    priority_queue<int, vector<int>, greater<int>> large;
    priority_queue<int, vector<int>, less<int>> small;

    auto add_nums = [&large, &small](int val) {
        if (large.size() > small.size()) {
            large.push(val);
            small.push(large.top());
            large.pop();
        } else {
            small.push(val);
            large.push(small.top());
            small.pop();
        }
    };

    for (const auto& num : nums1) add_nums(num);
    for (const auto& num : nums2) add_nums(num);

    if (large.size() > small.size()) {
        return large.top();
    } else if (large.size() < small.size()) {
        return small.top();
    } else {
        return (large.top() + small.top()) / 2.0;
    }
}

int main()
{
    vector<int> nums11 {1,3}, nums12 {2};
    cout << find_median_sorted_arrays(nums11, nums12) << endl;

    vector<int> nums21 {1,2}, nums22 {3,4};
    cout << find_median_sorted_arrays(nums21, nums22) << endl;

    return 0;
}

