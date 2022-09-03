#include <iostream>
#include <vector>
#include <algorithm>

#include "leetcode.h"

using namespace std;

vector<int> add(const vector<int>& A, const vector<int>& B)
{
    int N = A.size(), n = B.size();
    if (N < n) return add(B, A);

    vector<int> res;
    int s = 0;
    for (int i = 0; i < N; ++i) {
        s += A[i];
        if (i < B.size()) s += B[i];
        res.push_back(s % 10);
        s /= 10;
    }

    if (s) res.push_back(s);
    reverse(res.begin(), res.end());

    return res;
}

vector<int> add_to_array_form(vector<int>& num, int k)
{
    int n = num.size(), idx = 0;
    vector<int> kk;

    while (k) {
        kk.push_back(k % 10);
        k /= 10;
    }
    // reverse(kk.begin(), kk.end());

    reverse(num.begin(), num.end());

    return add(num, kk);
}

int main()
{
    vector<int> num1 { 1, 2, 0, 0 };
    cout << add_to_array_form(num1, 34) << endl;

    vector<int> num2 { 2, 7, 4 };
    cout << add_to_array_form(num2, 181) << endl;

    vector<int> num3 { 2, 1, 5 };
    cout << add_to_array_form(num3, 806) << endl;
    return 0;
}
