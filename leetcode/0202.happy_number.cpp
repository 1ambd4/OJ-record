#include <iostream>
#include <vector>

#include "leetcode.h"

using namespace std;

// 一百次还不快乐，就干脆别快乐了
bool is_happy_(int n)
{
    for (int i = 0; i < 100; ++i) {
        int sum = 0;
        while (n) {
            sum += (n % 10) * (n % 10);
            n /= 10;
        }
        if (sum == 1) return true;
        n = sum;
    }

    return false;
}

// 快慢指针，类似链表判环
// 快乐是相同的，最终一定会进入循环
// 如此，判断循环的时候，是否进入 1 -> 1 -> ... 1 循环即可
bool is_happy(int n)
{
    int slow = n, fast = n;

    auto calc = [](int x) {
        int sum = 0;
        while (x) {
            sum += (x % 10) * (x % 10);
            x /= 10;
        }
        return sum;
    };

    do {
        slow = calc(slow);
        fast = calc(fast);
        fast = calc(fast);
    } while (slow != fast);

    if (fast == 1) return true;
    return false;
}

int main()
{
    cout << is_happy(19) << endl;
    cout << is_happy(2) << endl;
    cout << is_happy(4) << endl;
    return 0;
}

