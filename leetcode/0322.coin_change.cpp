#include <iostream>
#include <vector>

using namespace std;

int coin_change(vector<int>& coins, int amount)
{
    vector<int> dp(amount+1, amount+1);

    dp[0] = 0;
    for (int i = 1; i <= amount; ++i) {
        for (const auto& coin : coins) {
            if (i - coin < 0) continue;
            dp[i] = min(dp[i], dp[i-coin]+1);
        }
    }

    return dp[amount] == amount + 1 ? -1 : dp[amount];
}

int _coin_change(vector<int>& coins, int amount)
{
    vector<int> dp(amount+1, amount+1);
    dp[0] = 0;

    for (int i = 1; i <= amount; ++i) {
        for (const auto& coin : coins) {
            if (i - coin < 0) {
                continue;
            }
            dp[i] = min(dp[i], dp[i-coin]+1);
        }
    }

    return dp[amount] == amount+1 ? -1 : dp[amount];
}

int main()
{
    vector<int> coins1 { 1, 2, 5 };
    cout << coin_change(coins1, 11) << endl;

    vector<int> coins2 { 2 };
    cout << coin_change(coins2, 3) << endl;

    vector<int> coins3 { 1 };
    cout << coin_change(coins3, 0) << endl;
    return 0;
}

