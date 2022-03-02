#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>

using namespace std;

int minimum_move(vector<int>& nums)
{
    int result = 0;
    sort(nums.begin(), nums.end(), std::greater<int>());

    for (int i = 1; i < nums.size(); ++i) {
        result += i * (nums[i-1] - nums[i]);
    }

    return result;
}

int main()
{
    vector<int> case1 { 1, 2, 3 };
    cout << minimum_move(case1) << endl;

    vector<int> case2 { 1, 3, 4 };
    cout << minimum_move(case2) << endl;

    vector<int> case3 { 1, 1, 1 };
    cout << minimum_move(case3) << endl;
    return 0;
}
