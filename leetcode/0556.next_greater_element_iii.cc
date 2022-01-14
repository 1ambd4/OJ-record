#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
#include <stack>
#include <climits>

using namespace std;

// 以为是和i一样的单调栈，就按单调栈做了
// 结果做着做着，就不是单调栈
// 也不能这么说，从单调栈入手是可以想出正确的解法的
// 即从后往前找到第一个逆序的位置k，与其后最末尾的比它大的元素交换位置后，升序排序k到末尾的所有元素
long next_greater_element(int n)
{
    vector<int> nums;

    while (n > 0) {
        int t = n % 10;
        nums.push_back(t);
        n /= 10;
    }
    reverse(nums.begin(), nums.end());

    long ans = 0;
    stack<int> s;
    vector<int> res(nums.size());
    for (int i = nums.size() - 1; i >= 0; --i) {
        while (!s.empty() && nums[i] >= nums[s.top()]) {
            s.pop();
        }
        res[i] = s.empty() ? -1 : s.top();
        s.push(i);
    }

    bool check = false;
    for_each(res.begin(), res.end(), [&check](const int &n){ if (n != -1) check = true; });
    if (check) {
        for (int i = res.size()-1; i >= 0; --i) {
            if (res[i] != -1) {
                // 不是交换逆序对，是和最后一个比它大的交换
                for (int j = nums.size()-1; j > i; --j) {
                    if (nums[i] < nums[j]) {
                        int t = nums[j];
                        nums[j] = nums[i];
                        nums[i] = t;
                        break;
                    }
                }

                sort(nums.begin()+i+1, nums.end());
                break;
            }
        }

        for (int i = 0; i < nums.size(); ++i) {
            ans = ans * 10 + nums[i];
        }

    } else {
        ans = -1;
    }

    return ans > INT_MAX ? -1 : static_cast<int>(ans);
}

int main()
{
    cout << next_greater_element(12) << endl;
    cout << next_greater_element(21) << endl;
    cout << next_greater_element(1234) << endl;
    cout << next_greater_element(230241) << endl;
    cout << next_greater_element(2147483486) << endl;
    cout << next_greater_element(2147483476) << endl;

    return 0;
}
