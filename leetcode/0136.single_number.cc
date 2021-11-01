#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

int single_number(vector<int>& nums) {
    int result = 0;
    for (const int& num : nums) {
        result ^= num;
    }
    return result;
}

int main(void) {
    vector<int> case1 { 2, 2, 1 };
    cout << single_number(case1) << endl;
    vector<int> case2 { 4, 1, 2, 1, 2 };
    cout << single_number(case2) << endl;
    return 0;
}
