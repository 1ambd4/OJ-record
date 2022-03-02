#include <iostream>
#include <vector>

using namespace std;

vector<int> sorted_squares(vector<int>& nums)
{
    for (int& num : nums) {
        num = num * num;
    }
    sort(nums.begin(), nums.end());
    return nums;
}

int main()
{
    vector<int> case1 { -4, -1, 0, 3, 10 };
    vector<int> result1 = sorted_squares(case1);
    for (const int& num : result1) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}
