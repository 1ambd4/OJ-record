#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

vector<int> two_sum(vector<int>& nums, int target)
{
    unordered_map<int, int> hashtable;
    for (int i = 0; i < nums.size(); ++i) {
        unordered_map<int, int>::iterator it = hashtable.find(target - nums[i]);
        if (it != hashtable.end()) {
            return { it->second, i };
        }
        hashtable[nums[i]] = i;
    }
    return { };
}

int main()
{
    vector<int> case1 { 2, 7, 11, 15 };
    vector<int> rest1 = two_sum(case1, 9);
    cout << rest1[0] << " " << rest1[1] << endl;

    vector<int> case2 { 3, 2, 4 };
    vector<int> rest2 = two_sum(case2, 6);
    cout << rest2[0] << " " << rest2[1] << endl;
    return 0;
}
