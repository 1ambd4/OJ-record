#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> reshaped_matrix(vector<vector<int>>& mat, int r, int c)
{
    if (mat.size() * mat[0].size() != r * c) {
        return mat;
    }

    vector<vector<int>> result;
    int t = c;
    vector<int> temp(c, 0);
    for (const auto& nums : mat) for (const auto& num : nums) {
        temp[c-t--] = num;
        if (t == 0) {
            t = c;
            result.push_back(temp);
        } 
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
