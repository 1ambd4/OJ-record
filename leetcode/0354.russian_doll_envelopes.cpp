#include <iostream>
#include <vector>
#include <algorithm>

#include "leetcode.h"

using namespace std;

int _max_envelopes(vector<vector<int>>& envelopes)
{
    auto cmp = [](vector<int>& a, vector<int>& b) {
        return a[0] != b[0] ? a[0] < b[0] : a[1] > b[1];
    };
    sort(envelopes.begin(), envelopes.end(), cmp);

    vector<int> heights(envelopes.size());
    for (int i = 0; i < envelopes.size(); ++i) {
        heights[i] = envelopes[i][1];
    }
    auto res = [&heights]() -> int {
        int piles = 0;
        vector<int> top(heights.size());

        for (int i = 0; i < heights.size(); ++i) {
            int poker = heights[i];
            int left = 0, right = piles;
            while (left < right) {
                int mid = (left + right) >> 1;
                if (top[mid] >= poker) right = mid;
                else left = mid + 1;
            }
            if (left == piles) ++piles;
            top[left] = poker;
        }
        return piles;
    }();

    return res;
}

// 定义dp[i]为以i为结尾的最长递增子序列长度
// O(n^2)的dp会TLE, (85/87)
int _max_envelopes(vector<vector<int>>& envelopes)
{
    int n = envelopes.size(), res = 0;
    vector<int> dp(n, 1);

    sort(envelopes.begin(), envelopes.end(), [](vector<int>& a, vector<int>& b){
            return a[0] != b[0] ? a[0] < b[0] : a[1] > b[1];
        });

    // cout << envelopes << endl;
    dp[0] = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (envelopes[i][1] > envelopes[j][1]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        res = max(res, dp[i]);
    }

    return res;
}

int main()
{
    vector<vector<int>> envelopes1 {{5,4}, {6,4}, {6,7}, {2,3}};
    cout << max_envelopes(envelopes1) << endl;

    vector<vector<int>> envelopes2 {{1,1}, {1,1}, {1,1}};
    cout << max_envelopes(envelopes2) << endl;
    return 0;
}

