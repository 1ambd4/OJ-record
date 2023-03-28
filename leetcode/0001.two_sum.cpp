#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

#include "leetcode.h"

using namespace std;

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
        if (inums[l][1] + inums[r][1] == target) {
            return {inums[l][0], inums[r][0]};
        } else if (inums[l][1] + inums[r][1] > target) {
            --r;
        } else {
            ++l;
        }
    }

    return { };
}

vector<int> _two_sum(vector<int>& nums, int target)
{
    int n = nums.size();
    vector<vector<int>> inums;
    for (int i = 0; i < n; ++i) {
        inums.push_back({i, nums[i]});
    }

    sort(inums.begin(), inums.end(), [](vector<int>& a, vector<int>& b){
            return a[1] < b[1];
    });

    // 二分最右
    for (int i = 0; i < n; ++i) {
        int l = i, r = n-1;
        int res = target - inums[i][1];
        while ( l < r) {
            int m = l + r + 1 >> 1;
            if (inums[m][1] <= res) l = m;
            else r = m - 1;
        }
        if (inums[l][1] == res) return {inums[i][0], inums[l][0]};
    }

    return { };
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
