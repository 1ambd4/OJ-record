#include <iostream>
#include <vector>

using namespace std;

void dfs(vector<vector<char>>& grid, int i, int j)
{
    if (i >= grid.size() || i < 0 || j >= grid[0].size() || j < 0) return;

    if (grid[i][j] == '0') return;

    vector<vector<int>> direction {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    grid[i][j] = '0';
    for (int k = 0; k < direction.size(); ++k) {
        dfs(grid, i+direction[k][0], j+direction[k][1]);
    }
}

int nums_of_lands(vector<vector<char>>& grid)
{
    int res = 0;
    for (int i = 0; i < grid.size(); ++i) {
        for (int j = 0; j < grid[0].size(); ++j) {
            if (grid[i][j] == '1') {
                ++res;
                dfs(grid, i, j);
            }
        }
    }
    return res;
}

int main()
{
    vector<vector<char>> grid1 {
        {'1','1','1','1','0'},
        {'1','1','0','1','0'},
        {'1','1','0','0','0'},
        {'0','0','0','0','0'}
    };
    cout << nums_of_lands(grid1) << endl;

    vector<vector<char>> grid2 {
        {'1','1','0','0','0'},
        {'1','1','0','0','0'},
        {'0','0','1','0','0'},
        {'0','0','0','1','1'}
    };
    cout << nums_of_lands(grid2) << endl;

    return 0;
}
