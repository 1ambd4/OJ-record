#include <iostream>
#include <vector>
#include <algorithm>

#include "leetcode.h"

using namespace std;

vector<int> sort_by_bits(vector<int>& arr)
{
    int n = arr.size();
    auto cmp = [](int a, int b){
        int ba = 0, bb = 0;
        int ta = a, tb = b;
        do {
            ba += a & 1;
        } while (a>>=1);
        do {
            bb += b & 1;
        } while (b>>=1);
        if (ba != bb) {
            return ba < bb;
        }
        return ta < tb;
    };

    sort(arr.begin(), arr.end(), cmp);
    return arr;
}

int main()
{
    vector<int> arr1 { 0, 1, 2, 3, 4, 5, 6, 7, 8 };
    vector<int> res1 = sort_by_bits(arr1);
    cout << res1 << endl;

    vector<int> arr2 { 2, 3, 5, 7, 11, 13, 17, 19 };
    vector<int> res2 = sort_by_bits(arr2);
    cout << res2 << endl;

    vector<int> arr3 { 1024, 512, 256, 128, 64, 32, 16, 8, 4, 2, 1 };
    vector<int> res3 = sort_by_bits(arr3);
    cout << res3 << endl;
    return 0;
}
