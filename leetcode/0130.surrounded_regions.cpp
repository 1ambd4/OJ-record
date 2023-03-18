#include <iostream>
#include <vector>
#include <queue>
#include <utility>

#include "leetcode.h"

using namespace std;


// 哭哩，dfs很好写嘛
void solve(vector<vector<char>>& board)
{
    int m = board.size();
    int n = board[0].size();
    vector<pair<int, int>> dirs {{1,0},{-1,0},{0,1},{0,-1}};
    vector<vector<bool>> visit(m, vector<bool>(n, false));

    auto adj = [m, n, &dirs](int i, int j) -> vector<pair<int, int>> {
        vector<pair<int, int>> res;
        for (const auto& [dx, dy] : dirs) {
            if (i + dx < 0 || i + dx >= m || j + dy < 0 || j + dy >= n) continue;
            res.emplace_back(i + dx, j + dy);
        }
        return res;
    };

    auto traverse = [&visit, &adj](auto&& self, vector<vector<char>>& board, int i, int j) -> void {
        if (visit[i][j] || board[i][j] == 'X') return ;
        if (board[i][j] == 'O') board[i][j] = '#';

        visit[i][j] = true;
        for (const auto& [x, y] : adj(i, j)) {
            self(self, board, x, y);
        }
    };

    for (int i = 0; i < m; ++i) {
        if (board[i][0] == 'O') traverse(traverse, board, i, 0);
        if (board[i][n-1] == 'O') traverse(traverse, board, i, n-1);
    }

    for (int j = 0; j < n; ++j) {
        if (board[0][j] == 'O') traverse(traverse, board, 0, j);
        if (board[m-1][j] == 'O') traverse(traverse, board, m-1, j);
    }

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (board[i][j] == 'O') board[i][j] = 'X';
            if (board[i][j] == '#') board[i][j] = 'O';
        }
    }
}

void _solve(vector<vector<char>>& board)
{
    int m = board.size();
    int n = board[0].size();
    vector<pair<int, int>> dirs {{1,0},{-1,0},{0,1},{0,-1}};

    auto adj = [m, n, &dirs](int i, int j) -> vector<pair<int, int>> {
        vector<pair<int, int>> res;
        for (const auto& [dx, dy] : dirs) {
            if (i + dx < 0 || i + dx >= m || j + dy < 0 || j + dy >= n) continue;
            // res.push_back({i + dx, j + dy});
            res.emplace_back(i + dx, j + dy);
        }
        return res;
    };

    queue<pair<int,int>> q;
    for (int i = 0; i < m; ++i) {
        if (board[i][0] == 'O') q.push({i,0});
        if (board[i][n-1] == 'O') q.push({i,n-1});
    }
    for (int j = 0; j < n; ++j) {
        if (board[0][j] == 'O') q.push({0,j});
        if (board[m-1][j] == 'O') q.push({m-1, j});
    }

    while (!q.empty()) {
        // 破案了，听chatgpt胡诌了半天，其实是多打了个引用符号
        // 用了引用取队首，然后出队，看起来似乎没什么问题
        // 但实际上这时候引用到的被出队的元素内存空间可能已经被回收了
        // 故而后面访问变量x和y的时候就会报错
        // auto& [x,y] = q.front();
        auto [x,y] = q.front();
        q.pop();
        board[x][y] = '#';

        for (const auto& [nx,ny] : adj(x,y)) {
            if (board[nx][ny] == 'O') {
                q.push({nx,ny});
            }
        }
    }

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (board[i][j] == 'O') board[i][j] = 'X';
            if (board[i][j] == '#') board[i][j] = 'O';
        }
    }
}

int main()
{
    vector<vector<char>> board1 {{'X', 'X', 'X', 'X'}, {'X','O','O','X'},{'X','X','O','X'},{'X','O','X','X'}};
    cout << board1 << endl;
    solve(board1);
    cout << board1 << endl;

    vector<vector<char>> board2 {{'O','O','O','O','X','X'},{'O','O','O','O','O','O'},{'O','X','O','X','O','O'},{'O','X','O','O','X','O'},{'O','X','O','X','O','O'},{'O','X','O','O','O','O'}};
    cout << board2 << endl;
    solve(board2);
    cout << board2 << endl;

    vector<vector<char>> board3 {{'O','X','O','O','O','O','O','O','O'},{'O','O','O','X','O','O','O','O','X'},{'O','X','O','X','O','O','O','O','X'},{'O','O','O','O','X','O','O','O','O'},{'X','O','O','O','O','O','O','O','X'},{'X','X','O','O','X','O','X','O','X'},{'O','O','O','X','O','O','O','O','O'},{'O','O','O','X','O','O','O','O','O'},{'O','O','O','O','O','X','X','O','O'}};
    cout << board3 << endl;
    solve(board3);
    cout << board3 << endl;

    return 0;
}

