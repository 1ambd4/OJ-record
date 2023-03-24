#include <iostream>
#include <vector>

using namespace std;

int can_complete_circuit(vector<int>& gas, vector<int>& cost)
{
    int n = gas.size(), sum = 0, msum = 0, id = 0;

    for (int i = 0; i < n; ++i) {
        sum += gas[i] - cost[i];
        if (sum < msum) {
            msum = sum;
            id = i + 1;
        }
    }

    if (sum < 0) return -1;

    return id == n ? 0 : id;
}

int main()
{
    vector<int> gas1 {1,2,3,4,5};
    vector<int> cost1 {3,4,5,1,2};
    cout << can_complete_circuit(gas1, cost1) << endl;

    vector<int> gas2 {2,3,4};
    vector<int> cost2 {3,4,5};
    cout << can_complete_circuit(gas2, cost2) << endl;

    vector<int> gas3 {3,1,1};
    vector<int> cost3 {1,2,2};
    cout << can_complete_circuit(gas3, cost3) << endl;

    return 0;
}

