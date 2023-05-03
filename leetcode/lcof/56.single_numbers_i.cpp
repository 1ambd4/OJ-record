#include <iostream>
#include <vector>
#include <cstdio>

std::vector<int> single_numbers(std::vector<int>& nums)
{
    int r = 0, x = 0;

    // 取得待求两数字的异或
    // 之后再尝试将其分开
    for (const int num : nums) x ^= num;

    // 既然这两个数字是不同的，那么异或的结果就是不相同的所有位
    // 只是想将这两个数字分到不同的两个组，那么随意按照不相同位中的任一位来分组即可
    // 那当然是取最低位了
    int flag = x & (-x);

    // 分组之后组内做异或-x
    for (const int num : nums) {
        if ((flag & num) != 0) {
            r ^= num;
        }
    }

    return std::vector<int>({r, r^x});
}

int main()
{
#ifdef LOCAL
    freopen("56.in", "r", stdin);
#endif
    int n = 0;
    while (std::cin >> n) {
        std::vector<int> v(n);
        for (int i = 0; i < n; ++i) std::cin >> v[i];
        std::vector<int> r = single_numbers(v);
        std::cout << r[0] << " " << r[1] << std::endl;
    }

    return 0;
}

