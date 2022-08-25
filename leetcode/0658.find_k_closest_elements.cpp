#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#include "leetcode.h"

using namespace std;

vector<int> find_closest_elements(vector<int>& arr, int k, int x)
{
    auto cmp = [x](int a, int b) -> bool {
        return abs(a-x) < abs(b-x) || abs(a-x) == abs(b-x) && a < b;
    };
    sort(arr.begin(), arr.end(), cmp);
    sort(arr.begin(), arr.begin()+k);
    return vector<int>(arr.begin(), arr.begin()+k);
}

int main()
{
    vector<int> arr1 { 1, 2, 3, 4, 5 };
    cout << find_closest_elements(arr1, 4, 3) << endl;
    return 0;
}

