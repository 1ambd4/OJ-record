#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> reshaped_matrix(vector<vector<int>>& mat, int r, int c)
{
    int m = mat.size(), n = mat[0].size();
    if (m * n != r * c) {
        return mat;
    }

    // 二维 -> 一维 -> 二维
    vector<vector<int>> result(r, vector<int>(c));
    for (int i = 0; i < m * n; ++i) {
        result[i/c][i%c] = mat[i/n][i%n];
    }

    return result;
}

int main()
{
    vector<vector<int>> case1 { {1, 2}, {3, 4} };
    cout << endl;
    vector<vector<int>> rst1 = reshaped_matrix(case1, 1, 4);
    for (const auto& nums : rst1) {
        for (const auto& num : nums) {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}
