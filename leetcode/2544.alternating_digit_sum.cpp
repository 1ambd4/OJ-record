#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int alternate_digit_sum(int n)
{
    int res = 0, sign = 1;

    for ( ; n > 0; n /= 10) {
        sign = -sign;
        res += n % 10 * sign;
    }

    // cout << sign << endl;

    // 精髓在这里
    // 如果数字n有奇数个数位，那么进到for循环里也是奇数次
    // 正数变换符号奇数次，那么就会变成负数
    // 也即最后最高位出循环的时候，最高位乘到的是一个负数
    // 这与题意不符合，此时只需要取反即可
    // 而很巧的是，符号位现在就是一个负数，相乘即可取反
    //
    // 当数字n有偶数个数位时，那么进到for循环里偶数次
    // 正数变换符号偶数次，最后仍然是一个正数
    // 即到最高位退出循环的时候，最高位乘到的是一个正数
    // 此时再乘一次符号位，并不改变结果
    // 但可以与奇数的情况相统一
    return res * sign;
}


// 转为字符串实际上是想改变遍历顺序
int _alternate_digit_sum(int n)
{
    stringstream ss(to_string(n));
    char c;
    int res = 0, sign = -1;

    while (ss >> c) {
        res += (c - '0') * (sign *= -1);
    }

    return res;
}


int __alternate_digit_sum(int n)
{
    int sign = -1;

    auto alter = [&sign](auto&& self, int n) -> int {
        return n == 0 ? 0 : self(self, n / 10) + n % 10 * (sign *= -1);
    };

    return alter(alter, n);

}


int main()
{
    cout << alternate_digit_sum(521) << endl;
    cout << alternate_digit_sum(111) << endl;
    cout << alternate_digit_sum(986996) << endl;

    return 0;
}

