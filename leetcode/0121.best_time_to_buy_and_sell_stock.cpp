#include <iostream>
#include <vector>
#include <array>
#include <limits>

using namespace std;

// 继续看dp[i][0]，同样发现只用到了上一个的值
// 故而也可以优化掉
int max_profit(vector<int>& prices)
{
    int minprice = numeric_limits<int>::max();
    int maxprofit = 0;

    for (const auto& price : prices) {
        minprice = min(minprice, price);
        maxprofit = max(maxprofit, price - minprice);
    }

    return maxprofit;
}

// dp[i][1]实际上只用到了上一个的数值
// 因而可以只用一个int保存，优化空间
int _max_profit(vector<int>& prices)
{
    int n = prices.size(), minp = prices[0];
    vector<int> dp(n, 0);

    for (int i = 1; i < n; ++i) {
        minp = min(minp, prices[i]);
        dp[i] = max(dp[i-1], prices[i] - minp);
    }

    return dp[n-1];
}

int __max_profit(vector<int>& prices)
{
    int n = prices.size();
    vector<array<int, 2>> dp(n, array<int, 2>());

    // dp[i][0]:第i天未持有股票时的最大收益
    // dp[i][1]:第i天持有股票时候的最大收益
    dp[0][0] = 0; dp[0][1] = prices[0];
    for (int i = 1; i < n; ++i) {
        // 高买低卖
        dp[i][1] = min(dp[i-1][1], prices[i]);
        dp[i][0] = max(dp[i-1][0], prices[i] - dp[i-1][1]);
    }

    return dp[n-1][0];
}

int main()
{
    vector<int> prices1 {7,1,5,3,6,4};
    cout << max_profit(prices1) << endl;

    vector<int> prices2 {7,6,4,3,1};
    cout << max_profit(prices2) << endl;

    return 0;
}

