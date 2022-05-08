#include <iostream>
#include <vector>

using namespace std;

vector<int> two_sum(vector<int>& nums, int target)
{
    for (int i = 0; i < nums.size(); ++i) {
        for (int j = 0; j < nums.size(); ++j) {
            if (i == j) continue;
            if (nums[i] + nums[j] == target) {
                return { i, j };
            }
        }
    }

    return { };
}

int main()
{
    vector<int> case1 { 2, 7, 11, 15 };
    vector<int> rest1 = two_sum(case1, 9);
    cout << rest1[0] << " " << rest1[1] << endl;

    vector<int> case2 { 3, 2, 4 };
    vector<int> rest2 = two_sum(case2, 6);
    cout << rest2[0] << " " << rest2[1] << endl;

    return 0;
}
