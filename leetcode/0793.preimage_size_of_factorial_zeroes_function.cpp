#include <iostream>
#include <vector>
#include <limits>

#include "leetcode.h"

using namespace std;

// 阶乘后有多少个零取决于能分解出多少个2*5
// 又因为2的个数必然多于5的个数，因而只需要考虑能分解出多少个5即可
long trailing_zeros(long n)
{
    long res = 0;
    for (long d = n; d / 5 > 0; d /= 5) {
        res += d / 5;
    }
    return res;
}

int lower_bound(int k)
{
    long l = 0, r = numeric_limits<long>::max() >> 1;
    while (l < r) {
        long m = (l + r) >> 1;
        if (trailing_zeros(m) >= k) r = m;
        else l = m + 1;
    }

    return l;
}

int upper_bound(int k)
{
    long l = 0, r = numeric_limits<long>::max() >> 1;
    while (l < r) {
        long m = (l + r + 1) >> 1;
        if (trailing_zeros(m) <= k) l = m;
        else r = m - 1;
    }

    return l;
}

int preimage_size_fzf(int k)
{
    return upper_bound(k) - lower_bound(k) + 1;
}

int main()
{
    cout << preimage_size_fzf(0) << endl;
    cout << preimage_size_fzf(5) << endl;
    cout << preimage_size_fzf(3) << endl;
    cout << preimage_size_fzf(28246) << endl;
    cout << preimage_size_fzf(1000000000) << endl;

    return 0;
}

