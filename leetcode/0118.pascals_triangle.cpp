#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> generate(int rows)
{
    if (rows == 1) return {{ 1 }};
    vector<vector<int>> ans(rows);
    ans[0].push_back(1);
    ans[1].push_back(1), ans[1].push_back(1);
    for (int i = 2; i < rows; ++i) {
        ans[i].push_back(1);
        for (vector<int>::iterator it = ans[i-1].begin(); it+1 != ans[i-1].end(); ++it) {
            ans[i].push_back(*it + *(it+1));
        }
        ans[i].push_back(1);
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
