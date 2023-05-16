#include <iostream>
#include <vector>
#include <cstdio>

// “十叉树“的前序遍历
std::vector<int> lexical_order(int n)
{
    std::vector<int> res;

    auto dfs = [&res, n](auto&& self, int v) -> void {
        if (v > n) return ;

        res.push_back(v);

        if (v * 10 > n) return ;
        for (int i = 0; i < 10; ++i) {
            self(self, v * 10 + i);
        }
    };

    for (int i = 1; i < 10; ++i) {
        dfs(dfs, i);
    }
    return res;
}

int main()
{
#ifdef LOCAL
    freopen("0386.in", "r", stdin);
#endif

    int n = 0;
    while (std::cin >> n) {
        std::vector<int> res = lexical_order(n);
        for (int i = 0; i < res.size(); ++i) {
            printf(",%d" + !i, res[i]);
        }
        printf("\n");
    }

    return 0;
}

