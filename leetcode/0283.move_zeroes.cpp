#include <iostream>
#include <vector>

using namespace std;

// 快慢指针，i指向0串首，j向后找非零元素，找到就交换数据
void move_zeroes(vector<int>& nums)
{
    int n = nums.size();
    for (int i = 0; i < n; ++i) {
        if (nums[i] != 0) {
            continue;
        }
        // 这时候i指向第一个0
        for (int j = i; j < n; ++j) {
            if (nums[j] != 0) {
                swap(nums[i], nums[j]);
                break;
            }
        }
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
