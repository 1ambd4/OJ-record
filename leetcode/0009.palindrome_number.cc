#include <iostream>

using namespace std;

// 难题不会做，简单题写得不优雅，太难了
bool is_palindrome(int x)
{
    // 排除一定不是回文数的情况
    // 1、负数定然不是回文数
    // 2、末尾有0的话，翻转后除了本身就是0，否则不可能是否回文数
    if (x < 0 || (x % 10 == 0 && x != 0)) return false;

    int rx = 0, tx = x;
    while (tx > rx) {
        rx = rx * 10 + tx % 10;
        tx /= 10;
    }

    return rx == tx || rx/10 == tx;
}

int main()
{
    cout << is_palindrome(121) << endl;
    cout << is_palindrome(-121) << endl;
    cout << is_palindrome(1) << endl;
    cout << is_palindrome(0) << endl;
    cout << is_palindrome(1234567899) << endl;
    return 0;
}
