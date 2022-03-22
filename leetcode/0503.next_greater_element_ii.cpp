#include <iostream>
#include <vector>
#include <stack>
#include <iterator>

using namespace std;

vector<int> next_greater_elements(vector<int>& nums)
{
    vector<int> tmp(nums), res(nums.size() * 2);
    copy(nums.begin(), nums.end(), back_inserter(tmp));
    stack<int> stk;
    for (int i = tmp.size()-1; i >= 0; --i) {
        while (!stk.empty() && stk.top() <= tmp[i]) {
            stk.pop();
        }
        res[i] = stk.empty() ? -1 : stk.top();
        stk.push(tmp[i]);
    }
    return vector<int>(res.begin(), res.begin()+nums.size());
}

int main()
{
    vector<int> v1 {1,2,1};
    vector<int> r1 = next_greater_elements(v1);
    copy(r1.begin(), r1.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    return 0;
}
