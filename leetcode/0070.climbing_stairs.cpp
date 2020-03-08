#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

int climb_stairs(int n) {
    vector<int> dp(n+1, 0);

    if (n == 1) return 1;

    dp[0] = 1, dp[1] = 1, dp[2] = 2;
    for (int i = 2; i <= n; ++i) {
        dp[i] = dp[i-1] + dp[i-2];
    }

    return dp[n];
}

int main(void) {

    int n_case1 = 2;
    assert(climb_stairs(2) == 2);

    int n_case2 = 3;
    assert(climb_stairs(3) == 3);

    int n_case3 = 1;
    assert(climb_stairs(1) == 1);

    cout << "Accepted by the test example!" << endl;

    return 0;
}