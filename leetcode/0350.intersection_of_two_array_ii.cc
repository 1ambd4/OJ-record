#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> intersect(vector<int>& nums1, vector<int>& nums2)
{
    if (nums1.size() > nums2.size()) {
        return intersect(nums2, nums1);
    }

    vector<int> result;
    unordered_map<int, int> hashtable;
    for (int num : nums1) {
        ++hashtable[num];
    }
    for (int num : nums2) {
        if (hashtable[num]) {
            --hashtable[num];
            result.push_back(num);
        }
    }

    return result;
}

int main()
{
    vector<int> nums1 = { 1, 2, 2, 1 };
    vector<int> nums2 = { 2, 2 };
    vector<int> result1 = intersect(nums1, nums2);
    for (const int& num : result1) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}
