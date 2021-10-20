#include <iostream>
#include <vector>

using namespace std;

// TLE，很欢乐
// void rotate(vector<int>& nums, int k)
// {
//     int n = nums.size();
//     for (int i = 0; i < k; ++i) {
//         int last_number = nums[n-1];
//         for (int j = n-1; j > 0; --j) {
//             nums[j] = nums[j-1];
//         }
//         nums[0] = last_number;
//     }
// }

// 408 2009年算法题，全部翻转，然后部分翻转
void reverse(vector<int>& nums, int start, int end)
{
    while (start < end) {
        swap(nums[start++], nums[end--]);
    }
}
void rotate(vector<int>& nums, int k)
{
    k %= nums.size();
    reverse(nums, 0, nums.size() - 1);
    reverse(nums, 0, k - 1);
    reverse(nums, k, nums.size() - 1);
}

int main()
{
    vector<int> case1 { 1, 2, 3, 4, 5, 6, 7 };
    rotate(case1, 3);
    for (const int& num : case1) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
