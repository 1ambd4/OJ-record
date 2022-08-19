#include <iostream>
#include <vector>

using namespace std;

int diagonal_sum(vector<vector<int>>& mat)
{
    int n = mat.size();
    int res = 0;

    for (int i = 0; i < n; ++i) {
        res += mat[i][i];
        res += mat[n-1-i][i];
    }

    if (n & 1) res -= mat[n/2][n/2];

    return res;
}

int main()
{
    vector<vector<int>> mat1 { {1,2,3}, {4,5,6}, {7,8,9} };
    cout << diagonal_sum(mat1) << endl;

    vector<vector<int>> mat2 { {1,1,1,1}, {1,1,1,1}, {1,1,1,1}, {1,1,1,1} };
    cout << diagonal_sum(mat2) << endl;

    vector<vector<int>> mat3 { {5} };
    cout << diagonal_sum(mat3) << endl;

    return 0;
}

