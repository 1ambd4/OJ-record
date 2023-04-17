#include <iostream>
#include <vector>

#include "leetcode.h"

using std::cin, std::cout;

std::vector<std::string> generate_parenthesis(int n)
{
    std::vector<std::string> res;
    if (n == 0) return res;

    std::string track;
    auto backtrack = [&res](auto&& self, int l, int r, std::string& track) -> void {
        // 边界条件
        // 首先因为最后必然要右括号来闭合，故剩余右括号数不可能小于左括号的
        // 其次剩余括号数都应该不小于0
        if (r < l) return ;
        if (l < 0 || r < 0) return ;

        // 处理找到的结果
        if (l == 0 && r == 0) {
            res.push_back(track);
            return ;
        }


        // 尝试放一个左括号
        track.push_back('(');
        self(self, l-1, r, track);
        track.pop_back();

        // 尝试放一个右括号
        track.push_back(')');
        self(self, l, r-1, track);
        track.pop_back();
    };

    // 参数依次为：剩余可用左括号数、剩余可用右括号数、中间结果
    backtrack(backtrack, n, n, track);

    return res;
}

int main()
{
    std::vector<std::string> res1 = generate_parenthesis(3);
    std::cout << res1 << std::endl;

    return 0;
}
