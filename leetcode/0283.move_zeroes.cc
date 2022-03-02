#include <iostream>
#include <vector>

using namespace std;

void move_zeroes(vector<int>& nums)
{
    int n = nums.size(), slow = 0, fast = 0;
    while (fast < n) {
        if (nums[fast]) {
            swap(nums[slow++], nums[fast]);
        }
        fast++;
    }
}

int main()
{
    vector<int> case1 { 0, 1, 0, 3, 12 };
    move_zeroes(case1);
    for (const int& num : case1) {
        cout << num << " ";
    }
    cout << endl;
    
    vector<int> case2 { 0, 0, 1, 3, 12 };
    move_zeroes(case2);
    for (const int& num : case2) {
        cout << num << " ";
    }
    cout << endl;
    
    return 0;
}
