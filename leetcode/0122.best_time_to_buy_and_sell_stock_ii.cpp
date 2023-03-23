#include <iostream>
#include <vector>
#include <array>

using namespace std;

int max_profit(vector<int>& prices)
{
    int n = prices.size();
    vector<array<int, 2>> dp(n, array<int, 2>());

    dp[0][0] = 0; dp[0][1] = prices[0];
    for (int i = 1; i < n; ++i) {
        dp[i][0] = max(dp[i-1][0], prices[i] - dp[i-1][1]);  // 保持或卖出
        dp[i][1] = min(dp[i-1][1], prices[i] - dp[i-1][0]);  // 保持或买入
    }

    return dp[n-1][0];
}

int main()
{
    vector<int> prices1 {7,1,5,3,6,4};
    cout << max_profit(prices1) << endl;

    vector<int> prices2 {1,2,3,4,5};
    cout << max_profit(prices2) << endl;

    vector<int> prices3 {7,6,4,3,1};
    cout << max_profit(prices3) << endl;

    return 0;
}

