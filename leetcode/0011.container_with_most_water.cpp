#include <iostream>
#include <vector>

using namespace std;


// 暴力算法需要O(n^2)，枚举所有可能的情况
// 但实际上 area = width * height = height * width
// 而且width与height是相关的，因而O(N)便可以做到
int max_area(vector<int>& height)
{
    int left = 0, right = height.size() - 1;
    int res = 0;

    while (left < right) {
        res = max(res, min(height[left], height[right]) * (right - left));

        // 盛水量是由较短的一边决定的
        // 想要更大的盛水量就需要改变较短边，寻找更优解
        if (height[left] < height[right]) {
            ++left;
        } else {
            --right;
        }
    }

    return res;
}

int main()
{
    vector<int> height1 { 1, 8, 6, 2, 5, 4, 8, 3, 7 };
    cout << max_area(height1) << endl;

    vector<int> height2 { 1, 1 };
    cout << max_area(height2) << endl;

    return 0;
}

