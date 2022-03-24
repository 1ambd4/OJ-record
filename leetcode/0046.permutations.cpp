#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void backtrace(vector<int>& nums, vector<vector<int>>& res, vector<int>& track)
{
    if (track.size() == nums.size()) {
        res.push_back(vector<int>(track));
        return;
    }

    for (int i = 0; i < nums.size(); ++i) {
        auto it = find(track.begin(), track.end(), nums[i]);
        if (it != track.end()) continue;
        track.push_back(nums[i]);
        backtrace(nums, res, track);
        track.pop_back();
    }
}

vector<vector<int>> permute(vector<int>& nums)
{
    vector<int> track;
    vector<vector<int>> res;
    backtrace(nums, res, track);
    return res;
}

int main()
{
    vector<int> nums1{1,2,3};
    vector<vector<int>> res1 = permute(nums1);
    for (const auto& pemu : res1) {
        for (const auto& e : pemu) {
            cout << e << ',';
        }
        cout << '\t';
    }
    cout << endl;

    vector<int> nums2{0,1};
    vector<vector<int>> res2 = permute(nums2);
    for (const auto& pemu : res2) {
        for (const auto& e : pemu) {
            cout << e << ',';
        }
        cout << '\t';
    }
    cout << endl;

    vector<int> nums3{1};
    vector<vector<int>> res3 = permute(nums3);
    for (const auto& pemu : res3) {
        for (const auto& e : pemu) {
            cout << e << ',';
        }
        cout << '\t';
    }
    cout << endl;
    return 0;
}
