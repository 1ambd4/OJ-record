#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int majority_element(std::vector<int>& nums)
{
    int n = nums.size();
    if (n == 1) return nums[0];

    int num = nums[0], cnt = 1;
    for (int i {1}; i < n; ++i) {
        if (nums[i] != num) {
            if (cnt > 0) --cnt;
            else num = nums[i], cnt = 1;
        } else {
            ++cnt;
        }
    }

    return num;
}

int _majority_element(vector<int>& nums)
{
    stack<int> s;
    for (const auto& num : nums) {
        if (s.empty()) {
            s.push(num);
            continue;
        }

        if (s.top() != num) {
            s.pop();
            continue;
        }

        s.push(num);
    }

    return s.top();
}

int main()
{
    vector<int> vec1{3,2,3};
    cout << majority_element(vec1) << endl;

    vector<int> vec2{2,2,1,1,1,2,2};
    cout << majority_element(vec2) << endl;
}
