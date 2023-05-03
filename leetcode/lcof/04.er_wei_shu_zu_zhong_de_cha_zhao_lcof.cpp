#include <iostream>
#include <vector>
#include <cstdio>

// 站在右上角看这个二维矩阵，实际上是一棵二叉搜索树
// 因而很容易想到类似的思路
bool find_number_in_2d_array(std::vector<std::vector<int>>& matrix, int target)
{
    int n = matrix.size();
    if (n == 0) return false;
    int m = matrix[0].size();
    if (m == 0) return false;

    int row = 0, col = m - 1;

    while (row < n && col >= 0) {
        if (matrix[row][col] == target) return true;
        else if (matrix[row][col] > target) --col;
        else if (matrix[row][col] < target) ++row;
    }

    return false;
}

int main()
{
#ifdef LOCAL
    freopen("04.in", "r", stdin);
#endif
    int n = 0, m = 0, t = 0;
    while (std::cin >> n >> m >> t) {
        std::vector<std::vector<int>> v(n, std::vector<int>(m, 0));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                std::cin >> v[i][j];
            }
        }

        std::cout << find_number_in_2d_array(v, t) << std::endl;
    }

    return 0;
}

