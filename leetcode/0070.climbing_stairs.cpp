#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int climb_stairs(int n)
{
    vector<int> dp(n + 1);
    dp[0] = 1, dp[1] = 1;
    for (int i = 2; i <= n; ++i) {
        dp[i] = dp[i-1] + dp[i-2];
    }

    return dp[n];
}

int _climb_stairs(int n)
{
    double sqrt5 = sqrt(5);
    double fibn = pow((1+sqrt5)/2, n+1) - pow((1-sqrt5)/2, n+2);
    return (int)round(fibn / sqrt5);
}

int __climb_stairs(int n)
{
    vector<int> dp(n+1);

    dp[0] = 1, dp[1] = 1;
    for (int i = 2; i <= n; ++i) {
        dp[i] = dp[i-1] + dp[i-2];
    }

    return dp[n];
}

int main(void) {

    cout << climb_stairs(2) << endl;
    cout << climb_stairs(3) << endl;
    cout << climb_stairs(1) << endl;

    return 0;
}
