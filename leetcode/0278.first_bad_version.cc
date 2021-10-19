#include <iostream>
#include <vector>

using namespace std;

bool isBadVersion(int n)
{
    return n >= 4;
}

int search(int n)
{ 
    // 既然是左闭右开区间了，right为啥不是 n+1 呢？我想不通，题解区和讨论区一水儿的 right = n
    // int left = 1, right = n;
    int left = 1, right = n + 1;

    while (left < right) {
        int mid = left + ((right-left) >> 1);

        if (isBadVersion(mid)) {
            right = mid;
        } else if (!isBadVersion(mid)) {
            left = mid + 1;
        }
    }

    return left;
}

int main()
{
    cout << search(5) << endl;
    // right = n + 1，会被卡int上限，改换long就好（毫无意义的卡数据
    // cout << search(2147483647) << endl;
    return 0;
}
