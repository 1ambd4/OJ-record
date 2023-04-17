#include <iostream>
#include <vector>

using std::vector, std::cin, std::cout;

bool is_valid_sudoku(vector<vector<char>>& board)
{
    vector<vector<bool>> row(9, vector<bool>(10, false));
    vector<vector<bool>> col(9, vector<bool>(10, false));
    vector<vector<bool>> box(9, vector<bool>(10, false));

    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            if (board[i][j] == '.') continue;

            int cur = board[i][j] - '0';
            if (row[i][cur]) return false;
            if (col[j][cur]) return false;
            // 这里比较难想的就是这个box了
            // 其实就是想办法将二维的坐标(i,j)映射到一维的[0,8]里
            if (box[j/3 + (i/3)*3][cur]) return false;

            row[i][cur] = true;
            col[j][cur] = true;
            box[j/3 + (i/3)*3][cur] = true;
        }
    }

    return true;
}

int main()
{
    return 0;
}
