#include <iostream>
#include <vector>

#include "leetcode.h"

using namespace std;

vector<int> prime_factorization(int x)
{
    vector<int> res;

    for (int i = 2; i <= x / i; ++i) {
        if (x % i == 0) {
            while (x % i == 0) x /= i;
            res.push_back(i);
        }
    }

    if (x > 1) res.push_back(x);

    return res;
}

bool is_ugly(int x)
{
    if (x <= 0) return false;
    vector<int> res = prime_factorization(x);
    int n = res.size();
    if (n > 3) return false;
    for (int i = 0; i < n; ++i) {
        switch(res[i]) {
            case 2:
            case 3:
            case 5:
                continue;
            default:
                return false;
        }
    }
    return true;
}

bool is_ugly_(int x)
{
    if (x <= 0) return false;
    while (x % 2 == 0) x /= 2;
    while (x % 3 == 0) x /= 3;
    while (x % 5 == 0) x /= 5;
    return x == 1;
}

int main()
{
    cout << is_ugly(6) << endl;
    cout << is_ugly(1) << endl;
    cout << is_ugly(14) << endl;
    cout << is_ugly(-2147483648) << endl;
    return 0;
}
