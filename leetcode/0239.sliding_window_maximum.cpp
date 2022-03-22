#include <iostream>
#include <vector>
#include <deque>
#include <iterator>

using namespace std;

class Deque {
public:
    // 队尾添加n
    void push(int n)
    {
        while (!que.empty() && que.back() < n) {
            que.pop_back();
        }
        que.push_back(n);
    }
    // 队头如果是n则删除
    void pop(int n)
    {
        if (que.front() == n) {
            que.pop_front();
        }
    }
    // 返回最大值
    int max()
    {
        return que.front();
    }
private:
    deque<int> que;
};

vector<int> max_sliding_window(vector<int>& nums, int k)
{
    Deque window;
    vector<int> res;

    for (int i = 0; i < nums.size(); ++i) {
        if (i < k-1) {
            window.push(nums[i]);
        } else {
            window.push(nums[i]);
            res.push_back(window.max());
            window.pop(nums[i-k+1]);
        }
    }

    return res;
}

int main()
{
    vector<int> nums1 {1,3,-1,-3,5,3,6,7};
    vector<int> res1 = max_sliding_window(nums1, 3);
    copy(res1.begin(), res1.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    vector<int> nums2 {1};
    vector<int> res2 = max_sliding_window(nums2, 1);
    copy(res2.begin(), res2.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    return 0;
}
