#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

int single_number(vector<int>& nums) {
    int result = 0;
    for (vector<int>::iterator it = nums.begin(); it != nums.end(); ++it) {
        result ^= *it;
    }

    return result;
}

int main(void) {
    vector<int> nums_case1 = {2, 2, 1};
    assert(single_number(nums_case1) == 1);

    vector<int> nums_case2 = {4, 1, 2, 1, 2};
    assert(single_number(nums_case2) == 4);

    cout << "Accepted by the test example!" << endl;

    return 0;
}