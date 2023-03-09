#include <iostream>
#include <vector>

using namespace std;

class NumMatrix {
public:
    NumMatrix(vector<vector<int>>& matrix)
    {
        int n = matrix.size(), m = matrix[0].size();
        if (n == 0) return ;

        ps.resize(n+1, vector<int>(m+1, 0));
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                ps[i][j] = ps[i-1][j] + ps[i][j-1] + matrix[i-1][j-1] - ps[i-1][j-1];
            }
        }
    }

    int sum_region(int r1, int c1, int r2, int c2)
    {
        return ps[r2+1][c2+1] - ps[r1][c2+1] - ps[r2+1][c1] + ps[r1][c1];
    }

private:
    vector<vector<int>> ps;
};



// 二维看作n个一维，性能并不算好
class _NumMatrix {
public:
    _NumMatrix(vector<vector<int>> &matrix)
    {
        if (matrix.size() == 0) return ;
        // preSum.resize(matrix.size());
        preSum.resize(matrix.size(), vector<int>(matrix[0].size()+1));
        for (int i = 0; i < preSum.size(); ++i) {
            // preSum[i].resize(matrix[i].size()+1);
            preSum[i][0] = 0;
            for (int j = 1; j < preSum[i].size(); ++j) {
                preSum[i][j] = preSum[i][j-1] + matrix[i][j-1];
            }
        }
    }

    int sum_region(int row1, int col1, int row2, int col2)
    {
        int sum = 0;
        for (int i = row1; i <= row2; ++i) {
            sum += (preSum[i][col2+1] - preSum[i][col1]);
        }
        return sum;
    }

    void show()
    {
        for (vector<int> &nums : preSum) {
            for (const int &num : nums) {
                cout << num << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

private:
    vector<vector<int>> preSum;
};

int main()
{
    vector<vector<int>> vec1 { {3, 0, 1, 4, 2},
                               {5, 6, 3, 2, 1},
                               {1, 2, 0, 1, 5},
                               {4, 1, 0, 1, 7},
                               {1, 0, 3, 0, 5} };
    NumMatrix *case1 = new NumMatrix(vec1);
    cout << case1->sum_region(2, 1, 4, 3) << ", "
        << case1->sum_region(1, 1, 2, 2) << ", "
        << case1->sum_region(1, 2, 2, 4) << endl;

    vector<vector<int>> vec2 { {-4, -5} };
    NumMatrix *case2 = new NumMatrix(vec2);
    cout << case2->sum_region(0, 0, 0, 0) << ", "
        << case2->sum_region(0, 0, 0, 1) << ", "
        << case2->sum_region(0, 1, 0, 1) << endl;

    return 0;
}
