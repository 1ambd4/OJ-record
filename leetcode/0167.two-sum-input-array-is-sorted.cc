#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// 既然是非递减顺序的，二分啊
// vector<int> two_sum(vector<int>& nums, int target)
// {
//     int n = nums.size();
//     for (int i = 0; i < n; ++i) {
//         int target_ = target - nums[i];
//         int left = i + 1, right = n - 1;
//         while (left <= right) {
//             int mid = left + ((right - left)>>1);
//             if (nums[mid] == target_) {
//                 return { i + 1, mid + 1 };
//             } else if (nums[mid] < target_) {
//                 left = mid + 1;
//             } else if (nums[mid] > target_) {
//                 right = mid - 1;
//             }
//         }
//     }
// 
//     return { };
// }

// 还能到O(n)？
vector<int> two_sum(vector<int>& nums, int target)
{
    int i = 0, j = nums.size() - 1;
    while (i < j) {
        int sum = nums[i] + nums[j];
        if (sum < target) {
            i++;
        } else if (sum > target) {
            j++;
        } else {
            return { i+1, j+1 };
        }
    }

    return { };
}

int main()
{
    vector<int> case1 { -10000, -1, 0, 1 };
    vector<int> rest1  = two_sum(case1, 1);
    for (const int& num : rest1) {
        cout << num << " ";
    }
    cout << endl;   

    return 0;
}
