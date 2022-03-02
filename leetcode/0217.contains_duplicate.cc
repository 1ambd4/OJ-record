#include <iostream>
#include <cassert>
#include <vector>
#include <unordered_set>
using namespace std;

// unordered_set底层是 hash table
bool contain_duplicate(vector<int>& nums) {
    unordered_set<int> s;
    for (const int& num : nums) {
        if (s.find(num) != s.end()) {
            return true;
        }
        s.insert(num);
    }
    return false;
}

int main(void) {
    vector<int> nums_case1 = {1, 2, 3, 1};
    assert(contain_duplicate(nums_case1) == true);

    vector<int> nums_case2 = {1, 2, 3, 4};
    assert(contain_duplicate(nums_case2) == false);

    cout << "Accepted by the test example!" << endl;

    return 0;
}
