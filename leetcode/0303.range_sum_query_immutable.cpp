#include <iostream>
#include <vector>

using namespace std;

class NumArray {
public:
    NumArray(vector<int>& nums)
    {
        pre_sum.resize(nums.size() + 1);
        pre_sum[0] = 0;
        for (int i = 1; i <= pre_sum.size(); ++i) {
            pre_sum[i] = pre_sum[i-1] + nums[i-1];
        }
    }

    int sum_range(int left, int right)
    {
        return pre_sum[right+1] - pre_sum[left];
    }

private:
    vector<int> pre_sum;
};


class _NumArray {
public:
    _NumArray(vector<int> &nums)
    {
        preSum.resize(nums.size()+1);
        preSum[0] = 0;
        for (int i = 1; i < preSum.size(); ++i) {
            preSum[i] = preSum[i-1] + nums[i-1];
        }
    }

    int sum_range(int left, int right)
    {
        return preSum[right+1] - preSum[left];
    }

private:
    vector<int> preSum;
};

int main()
{
    vector<int> vec1 { -2, 0, 3, -5, 2, -1 };
    NumArray *case1 = new NumArray(vec1);
    cout << case1->sum_range(0,2) << endl;
    cout << case1->sum_range(2,5) << endl;
    cout << case1->sum_range(0,5) << endl;
    return 0;
}
