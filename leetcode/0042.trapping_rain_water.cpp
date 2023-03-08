#include <iostream>
#include <vector>

using namespace std;

// 对每一个竹子而言，可以接的雨水等于左右两边最高柱子中较小的那一个减去当前柱子高度
int trap(vector<int>& height)
{
    int n = height.size();

    if (n == 0) return 0;

    int res = 0;
    vector<int> left(n, 0), right(n, 0);

    left[0] = height[0], right[n-1] = height[n-1];
    for (int i = 1; i < n; ++i) {
        left[i] = max(left[i-1], height[i]);
    }
    for (int i = n - 2; i >= 0; --i) {
        right[i] = max(right[i+1], height[i]);
    }

    for (int i = 0; i < n; ++i) {
        res += min(left[i], right[i]) - height[i];
    }

    return res;
}

int main()
{
    vector<int> height1 { 0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1 };
    cout << trap(height1) << endl;

    vector<int> height2 { 4, 2, 0, 3, 2, 5 };
    cout << trap(height2) << endl;

    return 0;
}

