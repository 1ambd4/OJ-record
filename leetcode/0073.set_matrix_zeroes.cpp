#include <iostream>
#include <vector>

using namespace std;

// 题说的常量空间指：另外开常量空间
// 也就是说，利用现有空间是OK的
void _set_zeroes(vector<vector<int>>& matrix)
{
    int m = matrix.size(), n = matrix[0].size();
    // O(m+n)的空间使用原数组的第一列第一行
    // 有union那味儿了
    bool row = false, col = false;

    // 预处理第一行/列
    for (int i = 0; i < m; ++i) {
        if (!matrix[i][0]) {
            row = true;
        }
    }
    for (int j = 0; j < n; ++j) {
        if (!matrix[0][j]) {
            col = true;
        }
    }

    // 遍历数组打标记
    for (int i = 1; i < m; ++i) {
        for (int j = 1; j < n; ++j) {
            if (matrix[i][j] == 0) {
                matrix[i][0] = matrix[0][j] = 0;
            }
        }
    }

    // 遍历修改数组
    for (int i = 1; i < m; ++i) {
        for (int j = 1; j < n; ++j) {
            if (matrix[i][0] || matrix[0][j]) {
                matrix[i][j] = 0;
            }
        }
    }

    // 更新第一列/行
    if (row) for (int i = 0; i < m; ++i) {
        matrix[i][0] = 0;
    }
    if (col) for (int j = 0; j < n; ++j) {
        matrix[0][j] = 0;
    }
}

// 再优化就是再减少一个变量，因为matrix[0][0]处于行列交点处
void set_zeroes(vector<vector<int>>& matrix)
{
    int m = matrix.size(), n = matrix[0].size();
    bool flag = false;

    for (int i = 0; i < m; ++i) {
        if (!matrix[i][0]) {
            flag = true;
        }
        for (int j = 1; j < n; ++j) {
            if (!matrix[i][j]) {
                matrix[i][0] = matrix[0][j] = 0;
            }
        }
    }

    for (int i = m-1; i >= 0; --i) {
        for (int j = 1; j < n; ++j) {
            if (!matrix[i][0] || !matrix[0][j]) {
                matrix[i][j] = 0;
            }
        }
        if (flag) {
            matrix[i][0] = 0;
        }
    }
}

int main()
{
    vector<vector<int>> case1 { {1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    set_zeroes(case1);
    for (const auto& nums : case1) {
        for (const auto& num : nums) {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}
