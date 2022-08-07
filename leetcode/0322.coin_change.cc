#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

// 状态转移方程
// dp[n] = 0                    (n=0)
// dp[n] = -1                   (n<0)
// dp[n] = min(dp[n-coin]+1)    (coin in coins, n>0)
int coin_change(vector<int>& coins, int amount) {
    vector<int> dp(amount+1, amount+1);
    dp[0] = 0;

    for (int i = 0; i < dp.size(); ++i) {
        for (int coin : coins) {
            if (i - coin < 0) continue;
            dp[i] = min(dp[i], dp[i-coin]+1);
        }
    }

    // 注意可能存在无法兑换的情况
    return dp[amount] == amount+1 ? -1 : dp[amount];
}

int main(void) {
    vector<int> coins_case1 {1, 2, 5};
    assert(coin_change(coins_case1, 11) == 3);

    vector<int> coins_case2 {2};
    assert(coin_change(coins_case2, 3) == -1);

    cout << "Accepted by the test example!" << endl;
    return 0;
}
