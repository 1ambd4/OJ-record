#include <iostream>
#include <vector>
#include <limits>
#include <numeric>

using namespace std;

int maximum_wealth(vector<vector<int>>& accounts)
{
    int maximum = numeric_limits<int>::min();
    for (const auto& account : accounts) {
        maximum = max(maximum, accumulate(account.begin(), account.end(), 0));
    }
    return maximum;
}

int main()
{
    vector<vector<int>> accounts1 { {1,2,3}, {3,2,1} };
    cout << maximum_wealth(accounts1) << endl;
    return 0;
}

