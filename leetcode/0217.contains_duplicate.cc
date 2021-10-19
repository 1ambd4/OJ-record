#include <iostream>
#include <cassert>
#include <vector>
#include <set>
using namespace std;

bool contain_duplicate(vector<int>& nums) {
    set<int> s(nums.begin(), nums.end());
    return s.size() != nums.size();
}

int main(void) {
    vector<int> nums_case1 = {1, 2, 3, 1};
    assert(contain_duplicate(nums_case1) == true);

    vector<int> nums_case2 = {1, 2, 3, 4};
    assert(contain_duplicate(nums_case2) == false);

    cout << "Accepted by the test example!" << endl;

    return 0;
}
