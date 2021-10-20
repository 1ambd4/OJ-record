#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>

using namespace std;

// 整体加等价于例外减
int minimum_move(vector<int>& nums)
{
    int result = 0;
    int minmun_number = *min_element(nums.begin(), nums.end());
    for (const int& num : nums) {
        result += num - minmun_number;
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
