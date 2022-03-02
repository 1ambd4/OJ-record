#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// TLE 娱乐一下 // vector<int> two_sum(vector<int>& nums, int target)
// {
//     int n = nums.size();
//     for (int i = 0; i < n; ++i) {
//         for (int j = 0; j < n; ++j) {
//             if (nums[i] + nums[j] == target && i != j) {
//                 return { i+1, j+1 };
//             }
//         }
//     }
//     return { };
// }

vector<int> two_sum(vector<int>& nums, int target)
{
    unordered_map<int, int> hashtable;
    int n = nums.size();
    for (int i = 0; i < n; ++i) {
        unordered_map<int, int>::iterator it = hashtable.find(target - nums[i]);
        if (it != hashtable.end()) {
            return { it->second+1, i+1 }; 
        }
        hashtable[nums[i]] = i;
    }
    return { };
}

int main()
{
    vector<int> case1 { 2, 7, 11, 15 };
    vector<int> rest1  = two_sum(case1, 9);
    for (const int& num : rest1) {
        cout << num << " ";
    }
    cout << endl;   

    return 0;
}
