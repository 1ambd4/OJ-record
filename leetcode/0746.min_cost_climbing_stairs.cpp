#include <iostream>
#include <vector>
#include <limits>

using namespace std;

// dp[i]: 从第i级登顶最少还需要支付的费用

int min_cost_climbing_stairs(vector<int>& cost)
{
    int n = cost.size();
    vector<int> dp(n+1, numeric_limits<int>::max());
    dp[n] = 0, dp[n-1] = cost[n-1];

    for (int i = n-2; i >= 0; --i) {
        dp[i] = min(dp[i+1], dp[i+2]) + cost[i];
    }

    return min(dp[0], dp[1]);
}

int main()
{
    vector<int> cost1 { 10, 15, 20 };
    cout << min_cost_climbing_stairs(cost1) << endl;

    vector<int> cost2 { 1, 100, 1, 1, 1, 100, 1, 1, 100, 1 };
    cout << min_cost_climbing_stairs(cost2) << endl;

    return 0;
}

