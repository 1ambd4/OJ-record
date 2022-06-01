#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

string largest_number(vector<int>& nums)
{
    auto cmp = [](int a, int b){
        string sa = to_string(a) + to_string(b);
        string sb = to_string(b) + to_string(a);
        return sa > sb;
    };
    sort(nums.begin(), nums.end(), cmp);

    stringstream ss;
    for (auto num : nums) {
        ss << to_string(num);
    }

    string res = ss.str();

    if (res[0] == '0') return "0";

    return res;
}

int main()
{
    vector<int> nums1 { 10, 2 };
    cout << largest_number(nums1) << endl;
    vector<int> nums2 { 3, 30, 34, 5, 9 };
    cout << largest_number(nums2) << endl;
    return 0;
}
