#include <iostream>
#include <stack>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> next_greater_element(vector<int> &nums1, vector<int> &nums2)
{
    unordered_map<int, int> m;
    vector<int> res(nums1.size());
    stack<int> s;

    for (int i = nums2.size() - 1; i >= 0; --i) {
        while (!s.empty() && s.top() <= nums2[i]) {
            s.pop();
        }
        m[nums2[i]] = s.empty() ? -1 : s.top();
        s.emplace(nums2[i]);
    }

    for (int i = 0; i < nums1.size(); ++i) {
        res[i] = m[nums1[i]];
    }

    return res;
}

int main()
{
    vector<int> case1_nums1 {4, 1, 2};
    vector<int> case1_nums2 {1, 3, 4, 2};
    vector<int> case1_res = next_greater_element(case1_nums1, case1_nums2);
    for (auto &e : case1_res) {
        cout << e << " ";
    }
    cout << endl;

    return 0;
}
