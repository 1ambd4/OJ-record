#include <iostream>
#include <vector>

using namespace std;

// 搜索空间优化
bool search(vector<vector<int>>& matrix, int target)
{
    int row = 0, col = matrix[0].size() - 1;
    while (row < matrix.size() && col < matrix[0].size()) {
        if (matrix[row][col] == target) {
            return true;
        } else if (matrix[row][col] < target) {
            ++row;
        } else if (matrix[row][col] > target) {
            --col;
        }
    }

    return false;
}

int main()
{
    vector<vector<int>> matrix { {1, 4, 7, 11, 15},  {2, 5, 8, 12, 19},  {3, 6, 9, 16, 22},
                                {10, 13, 14, 17, 24},  {18, 21, 23, 26, 30} };
    cout << search(matrix, 5) << endl;
    cout << search(matrix, 20) << endl;
    return 0;
}
