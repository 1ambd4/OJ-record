#include <iostream>
#include <vector>

using namespace std;

// left_bound
int search(vector<int>& nums, int target)
{
    if (target < *(nums.begin())) {
        return 0;
    } else if (target > *(nums.end()-1)) {
        return nums.size();
    }

    int l = 0, r = nums.size() - 1;
    while(l < r) {
        int m = (l + r) >> 1;
        if (nums[m] >= target) r = m;
        else l = m + 1;
    }

    return l;
}


int _search(vector<int>& nums, int target)
{
    if (target < *(nums.begin())) {
        return 0;
    } else if (target > *(nums.end()-1)) {
        return nums.size();
    }

    int left = 0, right = nums.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] == target) {
            return mid;
        } else if (nums[mid] > target) {
            right = mid - 1;
        } else if (nums[mid] < target) {
            left = mid + 1;
        }
    }

    return left;
}


int main()
{
    vector<int> case1 { 1, 3, 5, 6 };
    cout << search(case1, 5) << endl;
    cout << search(case1, 2) << endl;
    cout << search(case1, 7) << endl;
    cout << search(case1, 0) << endl;

    vector<int> case2 { 1 };
    cout << search(case2, 0) << endl;
    return 0;
}
