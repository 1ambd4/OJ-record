#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> generate(int rows)
{
    vector<vector<int>> ans(rows);
    for (int i = 0; i < rows; ++i) {
        ans[i].resize(i+1);
        // 这儿处理前两行的方法好巧妙
        ans[i][0] = ans[i][i] = 1;
        for (int j = 1; j < i; ++j) {
            ans[i][j] = ans[i-1][j] + ans[i-1][j-1];
        }
    }
    return ans;
}

int main()
{
    vector<vector<int>> ans1 = generate(9);
    for (const auto& nums : ans1) {
        for (const auto& num : nums) {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}
