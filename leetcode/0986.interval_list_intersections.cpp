#include <iostream>
#include <vector>

#include "leetcode.h"

using namespace std;

// 区间有交集需要：a2 >= b1 & b2 >= a1
// 而交集c1 = max(a1, b1)，c2 = min(a2, b2)
vector<vector<int>> interval_intersection(vector<vector<int>>& first, vector<vector<int>>& second)
{
    vector<vector<int>> res;
    int i = 0, j = 0;

    while (i < first.size() && j < second.size()) {
        if (first[i][1] >= second[j][0] && second[j][1] >= first[i][0]) {
            res.push_back({max(first[i][0], second[j][0]), min(first[i][1], second[j][1])});
        }

        if (first[i][1] < second[j][1]) {
            ++i;
        } else {
            ++j;
        }
    }

    return res;
}

int main()
{
    vector<vector<int>> first1 {{0,2}, {5,10}, {13,23}, {24,25}};
    vector<vector<int>> second1 {{1,5}, {8,12}, {15,24}, {25,26}};
    vector<vector<int>> res1 = interval_intersection(first1, second1);
    for (const auto& v : res1) print_vector(v);

    return 0;
}

