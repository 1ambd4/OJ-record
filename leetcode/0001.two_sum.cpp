#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

#include "leetcode.h"

using namespace std;

// 最妙的还是双指针了
vector<int> two_sum(vector<int>& nums, int target)
{
    int n = nums.size();
    vector<vector<int>> inums;
    for (int i = 0; i < n; ++i) {
        inums.push_back({i, nums[i]});
    }

    sort(inums.begin(), inums.end(), [](vector<int>& a, vector<int>& b){
            return a[1] < b[1];
    });

    int l = 0, r = n-1;
    while (l < r) {
        int cur = inums[l][1] + inums[r][1];
        if (cur == target) {
            return {inums[l][0], inums[r][0]};
        } else if (cur > target) {
            --r;
        } else {
            ++l;
        }
    }

    return { };
}


vector<int> _two_sum(vector<int>& nums, int target)
{
    using pii = pair<int, int>;
    int n = nums.size();
    vector<pii> inums;

    for (int i = 0; i < n; ++i) inums.push_back({i, nums[i]});
    sort(inums.begin(), inums.end(), [](pii& a, pii& b){
        return a.second < b.second;
    });

    for (int i = 0; i < n; ++i) {
        int res = target - inums[i].second;
        int l = i + 1, r = n-1;
        // 这里二分的时候注意一下
        // 如果二分找右边界，以防出现数字相同，返回结果的时候索引也相同的情况
        // l必须从i+1开始，因为一个数字是不许出现两次的
        // 但如果二分找左边界，那也不行啊，数据造得有点弱，233
        while (l < r) {
            int m = l + r >> 1;
            if (inums[m].second >= res) r = m;
            else l = m + 1;
        }
        if (inums[l].second == res) return {inums[i].first, inums[l].first};
    }

    return {};
}


vector<int> __two_sum(vector<int>& nums, int target)
{
    int n = nums.size();
    unordered_map<int, int> m;

    for (int i = 0; i < n; ++i) {
        auto iter = m.find(target - nums[i]);
        if (iter != m.end()) {
            return {iter->second, i};
        }
        m[nums[i]] = i;
    }
    return { };
}


vector<int> ___two_sum(vector<int>& nums, int target)
{
    for (int i = 0; i < nums.size(); ++i) {
        for (int j = i+1; j < nums.size(); ++j) {
            if (nums[i] + nums[j] == target) {
                return { i, j };
            }
        }
    }

    return { };
}


int main()
{
    vector<int> case1 {2,7,11,15};
    cout << two_sum(case1, 9) << endl;

    vector<int> case2 {3,2,4};
    cout << two_sum(case2, 6) << endl;

    vector<int> case3 {3,3};
    cout << two_sum(case3, 6) << endl;

    vector<int> case4 {0,4,3,0};
    cout << two_sum(case4, 0) << endl;

    return 0;
}
