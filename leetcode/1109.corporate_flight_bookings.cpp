#include <iostream>
#include <vector>

#include "leetcode.h"

using namespace std;

vector<int> corp_flight_bookings(vector<vector<int>>& bookings, int n)
{
    vector<int> res(n, 0), diff(n, 0);

    for (const auto& booking : bookings) {
        diff[booking[0]-1]   += booking[2];
        // 有些时候是需要检测一下边界的
        if (booking[1]-1+1 < n) {
            diff[booking[1]-1+1] -= booking[2];
        }
    }

    res[0] = diff[0];
    for (int i = 1; i < n; ++i) {
        res[i] = res[i-1] + diff[i];
    }

    return res;
}

int main()
{
    vector<vector<int>> bookings1 {{1,2,10}, {2,3,20}, {2,5,25}};
    vector<int> res1 = corp_flight_bookings(bookings1, 5);
    print_vector(res1);

    vector<vector<int>> bookings2 {{1,2,10}, {2,2,15}};
    vector<int> res2 = corp_flight_bookings(bookings2, 2);
    print_vector(res2);

    return 0;
}
