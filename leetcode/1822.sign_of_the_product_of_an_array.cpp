#include <iostream>
#include <vector>

using namespace std;

int sign_func(int x)
{
    if (x > 0) return 1;
    else if (x < 0) return -1;
    else return 0;
}

int array_sign(vector<int>& nums)
{
    int res = 1;
    for (const auto& num : nums) {
        res *= sign_func(num);
    }
    return res;
}

int main()
{
    vector<int> nums1 { -1, -2, -3, -4, 3, 2, 1 };
    cout << array_sign(nums1) << endl;
    return 0;
}

