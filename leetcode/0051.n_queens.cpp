#include <iostream>
#include <vector>
#include <string>

std::vector<std::vector<std::string>> solve_n_queens(int n)
{
    std::vector<std::vector<std::string>> res;
    std::vector<std::string> track(n, std::string(n, '.'));
    if (n == 0) return res;

    auto check = [&track, n](int row, int col) -> bool {
        // 列
        for (int i{0}; i < row; ++i) {
            if (track[i][col] == 'Q') {
                return false;
            }
        }

        // 主对角线方向
        for (int i{row-1}, j{col-1}; i >= 0 && j >= 0; --i, --j) {
            if (track[i][j] == 'Q') {
                return false;
            }
        }

        // 副对角巷方向
        for (int i{row-1}, j{col+1}; i >= 0 && j < n; --i, ++j) {
            if (track[i][j] == 'Q') {
                return false;
            }
        }

        return true;
    };

    auto backtracking = [&res, &track, n, check](auto&& self, int row) -> void {
        if (row == n) {
            res.push_back(track);
            return ;
        }

        for (int col{0}; col < n; ++col) {
            if (check(row, col)) {
                track[row][col] = 'Q';
                self(self, row+1);
                track[row][col] = '.';
            }
        }
    };

    backtracking(backtracking, 0);

    return res;
}

int main()
{
#ifdef LOCAL
    freopen("0051.in", "r", stdin);
#endif
    int n = 0;
    while (std::cin >> n) {
        std::vector<std::vector<std::string>> res = solve_n_queens(n);
        for (const auto& re : res) {
            for (const auto& e : re) {
                std::cout << e << " ";
            }
            std::cout << std::endl;
        }
    }

    return 0;
}

