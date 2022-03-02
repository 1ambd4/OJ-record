#include <iostream>
#include <vector>

using namespace std;

void set_zeroes(vector<vector<int>>& matrix)
{
    int m = matrix.size(), n = matrix[0].size();
    vector<bool> row(m, 0), col(n, 0);
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (matrix[i][j] == 0) {
                row[i] = col[j] = true; 
            }
        }
    }

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (row[i] || col[j]) {
                matrix[i][j] = 0;
            }
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
