#include <iostream>
#include <vector>

using namespace std;

bool can_jump(vector<int>& nums)
{
    int n = nums.size();
    vector<int> dp(n, 0);

    // 后判断过不了case3的那种情况
    for (int i = 0, dis = 0; i < n; ++i) {
        if (i > dis) return false;
        dis = max(dis, i + nums[i]);
        // if (dis <= i) return false;
    }
    return true;
}

int main()
{
    vector<int> nums1 {2,3,1,1,4};
    cout << can_jump(nums1) << endl;

    // 能不能跳到主要是看有么有0的出现
    // 没有0的话，必然可以向前走，因而一定能够跳到终点
    // 单下面这个例子有0,又刚好避不开这个0,因而跳不到终点
    vector<int> nums2 {3,2,1,0,4};
    cout << can_jump(nums2) << endl;

    vector<int> nums3 {0};
    cout << can_jump(nums3) << endl;
    return 0;
}

