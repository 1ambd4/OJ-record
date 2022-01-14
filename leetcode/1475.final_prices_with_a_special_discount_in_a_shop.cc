#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> final_price(vector<int> prices)
{
    vector<int> res(prices.size());
    stack<int> s;

    for (int i = prices.size()-1; i >= 0; --i) {
        while (!s.empty() && prices[i] < s.top()) {
            s.pop();
        }
        res[i] = prices[i] - (s.empty() ? 0 : s.top());
        s.push(prices[i]);
    }
    return res;
}

int main()
{
    vector<int> case1 {8, 4, 6, 2, 3};
    vector<int> res1 = final_price(case1);
    for (auto &e : res1) {
        cout << e << " ";
    }
    cout << endl;
    return 0;
}
