#include <iostream>
#include <vector>

using namespace std;

vector<int> sorted_squares(vector<int>& nums)
{
    int n = nums.size();
    vector<int> ans(n);
    for (int i = 0, j = n-1, pos = n-1; i <= j; ) {
        if (nums[i] * nums[i] > nums[j] * nums[j]) {
            ans[pos] = nums[i] * nums[i];
            ++i;
        } else {
            ans[pos] = nums[j] * nums[j];
            --j;
        }
        --pos;
    }
    return ans;
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
