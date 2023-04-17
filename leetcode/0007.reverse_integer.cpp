#include <iostream>

constexpr int MAX = 214748364;

int reverse(int x)
{
    int res = 0, digit = 0;

    while (x != 0) {
        digit = x % 10;
        // 容易想到因为参数给的就是int，
        // 因而溢出判断应该放在计算最后一位的时候进行
        //
        // 正溢出判断
        // 最大是2147483647，那么倒数第二位的时候大于4肯定会溢出
        // 如果等于4的话，那么还要判断最后一维是否小于等于7
        if (res > MAX || (res == MAX && digit > 7)) {
            return 0;
        }
        // 负溢出判断同理
        if (res < -MAX || (res == -MAX && digit < -8)) {
            return 0;
        }
        res = res * 10 + digit;
        x /= 10;
    }

    return res;
}


// 虽然leetcode禁止了这种ub
// 这种方法用了溢出最最最浅显的东西
// 即溢出后的结果就不是想要的值了
int _reverse(int x)
{
    int res = 0, pre = 0, digit = 0;

    while (x != 0) {
        digit = x % 10;
        pre = res;
        res = res * 10 + digit;
        if (res / 10 != pre) return 0;
        x /= 10;
    }

    return res;
}


int main()
{
    std::cout << reverse(123) << std::endl;
    std::cout << reverse(-123) << std::endl;
    std::cout << reverse(1534236469) << std::endl;

    return 0;
}
