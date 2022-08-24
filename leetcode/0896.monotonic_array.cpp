#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool is_monotonic__(vector<int>& nums)
{
    return is_sorted(nums.begin(), nums.end()) ||
        is_sorted(nums.rbegin(), nums.rend());
}

bool is_monotonic_(vector<int>& nums)
{
    if (nums.size() == 1) return true;
    int res = 0;
    auto increase = [&nums, &res](){
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] < nums[i-1]) return ;
        }
        ++res;
    };
    auto decrease = [&nums, &res](){
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] > nums[i-1]) return ;
        }
        ++res;
    };

    increase();
    decrease();
    if (res == 0) return false;
    return true;
}
    
bool is_monotonic(vector<int>& nums)
{
    bool inc { true }, dec { true };
    for (int i = 1; i < nums.size(); ++i) {
        if (nums[i] > nums[i-1]) dec = false;   
        if (nums[i] < nums[i-1]) inc = false;
    }
    return inc || dec;
}

int main()
{
    vector<int> nums1 { 1, 2, 2, 3 };
    cout << is_monotonic(nums1) << endl;

    vector<int> nums2 { 6, 5, 4, 4 };
    cout << is_monotonic(nums2) << endl;

    vector<int> nums3 { 1, 1, 1, 1 };
    cout << is_monotonic(nums3) << endl;

    vector<int> nums4 { 1, 1, 2 };
    cout << is_monotonic(nums4) << endl;
    return 0;
}

