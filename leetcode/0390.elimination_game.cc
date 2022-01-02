#include <iostream>

using namespace std;


// 2^a <= n < 2^b   需要操作 a 次
// 行吧，不会写，摆烂了
int last_remaining(int n)
{
    // 官方题解评论区里的这个解法属实看不懂了
    int mask = (1 << (31 - __builtin_clz(n))) - 1;
    return ((n | 0x55555555) & mask) + 1;
}

int main()
{
    cout << last_remaining(9) << endl;
    return 0;
}
