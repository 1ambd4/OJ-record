#include <iostream>
#include <vector>
#include <cstdio>

// 之前做过类似的，可以哈希到原数组，但这里不能改动原数组，因而不适用
// 这里有很巧妙的方法，就是把数组当作链表进行floyd判圈
// 哈希的方法其实也是相同的思想，只是实现不同罢了
int find_duplicate(std::vector<int>& nums)
{
    // int slow = 0;

    // for (int fast = 0; slow != fast || fast == 0; ) {
    //     slow = nums[slow];
    //     fast = nums[nums[fast]];
    // }

    // for (int i = 0; slow != i; i = nums[i]) {
    //     slow = nums[slow];
    // }


    int slow = 0, fast = 0;

    do {
        slow = nums[slow];
        fast = nums[nums[fast]];
    } while (slow != fast);

    slow = 0;
    while (slow != fast) {
        slow = nums[slow];
        fast = nums[fast];
    }

    return slow;
}

int main()
{
#ifdef LOCAL
    freopen("0287.in", "r", stdin);
#endif
    int n = 0;
    while (std::cin >> n) {
        std::vector<int> nums(n);
        for (int i = 0; i < n; ++i) std::cin >> nums[i];
        std::cout << find_duplicate(nums) << std::endl;
    }


    return 0;
}

