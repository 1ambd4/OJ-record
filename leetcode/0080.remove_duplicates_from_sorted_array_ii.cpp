#include <iostream>
#include <vector>
#include <cstdio>

int remove_duplicates(std::vector<int>& nums)
{
    int n = nums.size();
    if (n <= 2) return n;

    int left = 2, right = 2;
    while (right < n) {
        if (nums[right] != nums[left-2]) {
            nums[left++] = nums[right];
        }
        ++right;
    }

    return left;
}

int _remove_duplicates(std::vector<int>& nums)
{
    int n = nums.size();
    if (n <= 2) return n;

    int left = 1, right = 1;
    while (right < n) {
        if (nums[left-1] != nums[right]) {
            nums[++left] = nums[right];
        }
        ++right;
    }

    return left + 1;
}

int main()
{
#ifdef LOCAL
    freopen("0080.in", "r", stdin);
#endif
    int n = 0;
    while (std::cin >> n) {
        std::vector<int> v(n);
        for (int i{0}; i < n; ++i) std::cin >> v[i];
        std::cout << remove_duplicates(v) << std::endl;
    }

    return 0;
}

