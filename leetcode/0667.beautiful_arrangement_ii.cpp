#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>

#include "leetcode.h"

using namespace std;

vector<int> construct_array_(int n, int k)
{
    vector<int> res(n);
    for (int i = 0; i < n; ++i) res[i] = i + 1;

    while (next_permutation(res.begin(), res.end())) {
        bitset<10> m;
        for (int i = 1; i < n; ++i) {
            m[abs(res[i] - res[i-1])] = true;
        }
        if (m.count() == k) return res;
    }

    return res;
}

// 找规律
vector<int> construct_array(int n, int k)
{
    vector<int> res;

    for (int i = 1; i < n - k; ++i) res.push_back(i);
    for (int i = n - k, j = n; i <= j; ++i, --j) {
        res.push_back(i);
        if (i != j) res.push_back(j);
    }
    
    return res;
}

int main()
{
    cout << construct_array(3, 1) << endl;
    cout << construct_array(3, 2) << endl;
    cout << construct_array(5, 4) << endl;
    // cout << construct_array(92, 80) << endl;
    cout << construct_array(10, 8) << endl;
    cout << construct_array(10, 7) << endl;
    cout << construct_array(9, 8) << endl;
    return 0;
}

