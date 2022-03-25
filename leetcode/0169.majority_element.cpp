#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int majority_element(vector<int>& nums)
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
