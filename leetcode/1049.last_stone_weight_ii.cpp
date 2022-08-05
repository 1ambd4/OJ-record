#include <iostream>
#include <vector>

using namespace std;

// 题目的意思是想将一堆数字尽可能分成和相等的两部分
// 此题每次的选取是任意的，而T1046要求每次选择最大的两个
// 那只要让其中一堆尽可能接近总和的一半
// 易知此时是满足题意的一种分法
int last_stone_weight_ii(vector<int>& stones)
{
    int sum = 0;
    for (const auto& stone : stones) {
        sum += stone;
    }

    int w = sum / 2, n = stones.size();
    vector<vector<int>> dp(n+1, vector<int>(w+1, 0));

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= w; ++j) {
            if (j - stones[i-1] < 0) {
                dp[i][j] = dp[i-1][j];
            } else {
                dp[i][j] = max(dp[i-1][j-stones[i-1]] + stones[i-1], dp[i-1][j]);
            }
        }
    }

    return abs(sum - 2 * dp[n][w]);
}

int main()
{
    vector<int> stones1 { 2, 7, 4, 1, 8, 1 };
    cout << last_stone_weight_ii(stones1) << endl;

    vector<int> stones2 { 31, 26, 33, 21, 40 };
    cout << last_stone_weight_ii(stones2) << endl;

    vector<int> stones3 { 4, 3, 4, 3, 2 };
    cout << last_stone_weight_ii(stones3) << endl;

    return 0;
}

