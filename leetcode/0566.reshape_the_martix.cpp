#include <iostream>
#include <vector>

#include "leetcode.h"

using namespace std;

vector<vector<int>> reshaped_matrix(vector<vector<int>>& mat, int r, int c)
{
    int n = mat.size(), m = mat[0].size();
    if (n * m != r * c) return mat;

    vector<vector<int>> res;
    int t = c;
    vector<int> temp(c, 0);
    for (const auto& nums : mat) for (const auto& num : nums) {
        temp[c-t--] = num;
        if (!t) {
            t = c;
            res.push_back(temp);
        }
    }

    return res;
}

int main()
{
    vector<vector<int>> case1 { {1, 2}, {3, 4} };
    vector<vector<int>> res1 = reshaped_matrix(case1, 1, 4);
    cout << res1 << endl;

    return 0;
}
