#include <iostream>
#include <vector>
#include "leetcode.h"

using namespace std;

vector<vector<int>> subset(vector<int>& nums)
{
    int n = nums.size();
    vector<vector<int>> res;
    vector<int> track;

    auto backtrack = [&res, &n](auto&& self, vector<int>& nums, vector<int>& track, int id) -> void {
        res.push_back(track);

        for (int i = id; i < n; ++i) {
            track.push_back(nums[i]);
            self(self, nums, track, i + 1);
            track.pop_back();
        }
    };

    backtrack(backtrack, nums, track, 0);

    return res;
}


void _backtrace(vector<int>& nums, int s, vector<vector<int>>& res, vector<int>& track)
{
    res.push_back(vector<int>(track));

    for (int i = s; i < nums.size(); ++i) {
        track.push_back(nums[i]);
        _backtrace(nums, i+1, res, track);
        track.pop_back();
    }
}

vector<vector<int>> _subset(vector<int>& nums)
{
    vector<vector<int>> res;
    vector<int> track;
    _backtrace(nums, 0, res, track);
    return res;
}

int main()
{
    vector<int> nums1{1,2,3};
    vector<vector<int>> res1 = subset(nums1);
    cout << res1 << endl;
    return 0;
}
