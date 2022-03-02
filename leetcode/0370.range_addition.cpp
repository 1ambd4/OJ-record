#include <iostream>
#include <vector>

using namespace std;

class Difference{
public:
    Difference(vector<int> nums)
    {
        diff.resize(nums.size(), 0);
        diff[0] = nums[0];
        for (int i = 1; i < diff.size(); ++i) {
            diff[i] = nums[i] - nums[i-1];
        }
    }
    void increment(int i, int j, int val)
    {
        diff[i] += val;
        if (j+1 < diff.size()) {
            diff[j+1] -= val;
        }
    }
    vector<int> result()
    {
        vector<int> res(diff.size(), 0);
        res[0] = diff[0];
        for (int i = 1; i < res.size(); ++i) {
            res[i] = res[i-1] + diff[i];
        }
        return res;
    }
private:
    vector<int> diff;
};

vector<int> get_modified_array(vector<int> nums, int length, vector<vector<int>> ops)
{
    Difference *df = new Difference(nums);
    for (vector<int> op : ops) {
        df->increment(op[0], op[1], op[2]);
    }
    return df->result();
}

int main()
{
    vector<int> vec1(5, 0);
    vector<vector<int>> ops { {1, 3, 2}, {2, 4, 3}, {0, 2, -2} };
    vector<int> res1 = get_modified_array(vec1, 5, ops);
    for (const auto &num : res1) {
        cout << num << " ";
    }
    return 0;
}
