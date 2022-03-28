#include <iostream>
#include <vector>
#include <algorithm>

#include "leetcode.h"

using namespace std;

vector<int> intersection(vector<int>& nums1, vector<int>& nums2)
{
    vector<int> res;
    sort(nums2.begin(), nums2.end());

    auto fnd = [&nums2](const int x) -> bool {
        int left = 0, right = nums2.size()-1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums2[mid] == x) return true;
            else if (nums2[mid] > x) right = mid - 1;
            else if (nums2[mid] < x) left = mid + 1;
        }
        return false;
    };

    for (const auto& e : nums1) {
        if (fnd(e)) res.push_back(e);
    }

    sort(res.begin(), res.end());
    auto last = unique(res.begin(), res.end());
    res.erase(last, res.end());

    return res;
}

int main()
{
    vector<int> nums1{1,2,2,1}, nums2{2,2};
    vector<int> res = intersection(nums1, nums2);
    cout << res << endl;
    return 0;
}
