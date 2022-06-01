#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int gcd(int a, int b)
{
    if (b == 0) return a;
    else return gcd(b, a%b);
}

int find_gcd(vector<int>& nums)
{
    auto get_max_and_min_num = [&]() {
        if (nums.size() == 0) return pair<int, int>{ 0, 0 };
        int max_num = nums[0];
        int min_num = nums[0];
        for (int num : nums) {
            max_num = num > max_num ? num : max_num;
            min_num = num < min_num ? num : min_num;
        }
        return pair<int,int>{ max_num, min_num };
    };
    // c++17 structured binding declaration 好耶
    auto [max, min] {get_max_and_min_num()};
    return gcd(max, min);
}

int main()
{
    vector<int> nums1 { 2, 5, 6, 9, 10 };
    cout << find_gcd(nums1) << endl;

    return 0;
}
