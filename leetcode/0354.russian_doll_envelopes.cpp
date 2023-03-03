#include <iostream>
#include <vector>
#include <algorithm>

#include "leetcode.h"

using namespace std;

int max_envelopes(vector<vector<int>>& envelopes)
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

int main()
{
    vector<vector<int>> envelopes1 {{5,4}, {6,4}, {6,7}, {2,3}};
    cout << max_envelopes(envelopes1) << endl;

    vector<vector<int>> envelopes2 {{1,1}, {1,1}, {1,1}};
    cout << max_envelopes(envelopes2) << endl;
    return 0;
}

