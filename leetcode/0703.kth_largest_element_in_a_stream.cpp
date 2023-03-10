#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class kth_largest {
public:
    kth_largest(int k, vector<int>& nums) : k(k)
    {
        for (const auto& num : nums) {
            pq.push(num);
            if (pq.size() > k) pq.pop();
        }
    }

    int add(int val)
    {
        pq.push(val);
        if (pq.size() > k) {
            pq.pop();
        }
        return pq.top();
    }

private:
    int k;
    priority_queue<int, vector<int>, greater<int>> pq;
};

int main()
{
    vector<int> nums1 {4,5,8,2};
    kth_largest kl(3, nums1);
    cout << kl.add(3) << endl;
    cout << kl.add(5) << endl;
    cout << kl.add(10) << endl;
    cout << kl.add(9) << endl;
    cout << kl.add(4) << endl;

    return 0;
}

