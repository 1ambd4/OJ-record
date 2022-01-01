#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

vector<vector<int>> construct_2d_array(vector<int>& original, int m, int n)
{
    int len = original.size();
    if (len != m * n) return vector<vector<int>>();

    vector<vector<int>> res;
    // for (int i = 0; i < m; ++i) {
    //     vector<int> tmp; 
    //     copy(original.begin() + i * n, original.begin() + (i+1) * n, inserter(tmp, tmp.begin()));
    //     res.push_back(tmp);
    // }
    
    for (auto it = original.begin(); it != original.end(); it += n) {
        res.emplace_back(it, it + n);
    }

    return res;
}

int main()
{
    vector<int> case1 { 1, 2, 3, 4 };
    vector<vector<int>> res1 = construct_2d_array(case1, 2, 2);

    vector<int> case2 { 1, 2, 3 };
    vector<vector<int>> res2 = construct_2d_array(case2, 1, 3);

    vector<int> case3 { 1, 2, 3 };
    vector<vector<int>> res3 = construct_2d_array(case3, 1, 1);

    for (auto &v : res2) {
        for (auto &e : v) {
            cout << e << " ";
        }
        cout << endl;
    }
    return 0;
}
