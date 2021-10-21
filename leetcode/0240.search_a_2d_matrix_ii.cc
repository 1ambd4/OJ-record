#include <iostream>
#include <vector>

using namespace std;

// 搜索空间优化
bool search(vector<vector<int>>& matrix, int target)
{
    int cow = 0, row = matrix[0].size() - 1;
    while (cow < matrix.size() && row > 0) {
        if (matrix[cow][row] < target) {
            ++cow;
        } else if (matrix[cow][row] > target) {
            --row;
        } else {
            return true;
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
