#include <iostream>
#include <vector>

#include "leetcode.h"

using namespace std;

void backtrace(int n, int k, int s, vector<vector<int>>& res, vector<int>& track)
{
    if (track.size() == k) {
        res.push_back(vector<int>(track));
        return;
    }

    for (int i = s; i <= n; ++i) {
        track.push_back(i);
        backtrace(n, k, i+1, res, track);
        track.pop_back();
    }
}

vector<vector<int>> combine(int n, int k)
{
    vector<vector<int>> res;
    vector<int> track;
    backtrace(n, k, 1, res, track);
    return res;
}

int main()
{
    vector<vector<int>> res1 = combine(4, 2);
    cout << res1 << endl;
    return 0;
}
