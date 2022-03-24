#include <iostream>
#include <vector>

using namespace std;

void backtrace(vector<int>& nums, int s, vector<vector<int>>& res, vector<int>& track)
{
    res.push_back(vector<int>(track));

    for (int i = s; i < nums.size(); ++i) {
        track.push_back(nums[i]);
        backtrace(nums, i+1, res, track);
        track.pop_back();
    }
}

vector<vector<int>> subset(vector<int>& nums)
{
    vector<vector<int>> res;
    vector<int> track;
    backtrace(nums, 0, res, track);
    return res;
}

int main()
{
    vector<int> nums1{1,2,3};
    vector<vector<int>> res1 = subset(nums1);
    for (const auto& es : res1) {
        cout << '[';
        for (const auto& e : es) {
            cout << e << ',';
        }
        cout << ']' << endl;
    }
    return 0;
}
