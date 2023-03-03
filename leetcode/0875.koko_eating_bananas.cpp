#include <iostream>
#include <vector>

#include "leetcode.h"

using namespace std;

// h = f(k)，易知f(k)是单调不增的
int f(vector<int>& piles, int k)
{
    int res = 0;
    for (const auto& pile : piles) {
        res += pile / k;
        if (pile % k != 0) ++res;
    }
    return res;

}

// 寻找f(k)=h的最小k
int min_eating_speed(vector<int>& piles, int h)
{
    int l = 1, r = 1e9l + 1;
    while (l < r) {
        int m = (l + r) >> 1;
        if (f(piles, m) <= h) r = m;
        else l = m + 1;
    }

    return l;
}


int _f(vector<int> &piles, int k)
{
    int hours = 0;
    for (const int &pile : piles) {
        hours += pile / k;
        if (pile % k != 0) {
            hours++;
        }
    }
    return hours;
}

int _min_eating_speed(vector<int> &piles, int h)
{
    int left = 1, right = 1e9+1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (f(piles, mid) == h) {
            right = mid - 1;
        } else if (f(piles, mid) < h) {
            right = mid -1;
        } else if (f(piles, mid) > h) {
            left = mid + 1;
        }
    }

    return left;
}

int main()
{
    vector<int> piles1 {3,6,7,11};
    cout << min_eating_speed(piles1, 8) << endl;
    vector<int> piles2 {30,11,23,4,20};
    cout << min_eating_speed(piles2, 5) << endl;
    vector<int> piles3 {30,11,23,4,20};
    cout << min_eating_speed(piles3, 6) << endl;

    return 0;
}
