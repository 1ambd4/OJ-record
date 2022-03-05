#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

int remove_duplicates(vector<int>& nums) {
    int cnt = 0, len = nums.size();
    if (len == 0) return 0;
    for (int i = 1; i < len; ++i) {
        if (nums[i] != nums[cnt]) {
            nums[++cnt] = nums[i];
        }
    }

    return cnt + 1;
}

int main(void) {
    // 为空可太...
    vector<int> nums_case1{};
    assert(remove_duplicates(nums_case1) == 0);

    vector<int> nums_case2 {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    assert(remove_duplicates(nums_case2) == 5);

    cout << "Accepted by the test example!" << endl;
    
    return 0;
}
