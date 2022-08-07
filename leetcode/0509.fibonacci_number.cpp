#include <iostream>
#include <vector>

using namespace std;

int fib(int n)
{
    if (n == 0 || n == 1) {
        return 1;
    }
    return fib(n-1) + fib(n-2);
}

int fib_ms(int n);
int fib_ms_(vector<int>& memo, int n)
{
    if (memo[n] != 0) {
        return memo[n];
    }
    return memo[n] = fib_ms(n-1) + fib(n-2);
}

int fib_ms(int n)
{
    vector<int> memo(n+1, 0);
    memo[0] = 0, memo[1] = 1;
    return fib_ms_(memo, n);
}

int fib_dp(int n)
{
    vector<int> dp(n+1, 0);
    dp[0] = 0, dp[1] = 1;
    
    for (int i = 2; i <= n; ++i) {
        dp[i] = dp[i-1] + dp[i-2];
    }

    return dp[n];
}

int fib_dp_sc(int n)
{
    if (n == 0) return 0;
    int prev = 0, curr = 1, next = -1;

    for (int i = 2; i <= n; ++i) {
        next = prev + curr;
        prev = curr;
        curr = next;    
    }

    return curr;
}

int main()
{
    cout << fib_dp_sc(0) << endl;
    cout << fib_dp_sc(1) << endl;
    cout << fib_dp_sc(2) << endl;
    cout << fib_dp_sc(3) << endl;
    cout << fib_dp_sc(4) << endl;
    return 0;
}

