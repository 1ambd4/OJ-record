#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> daily_temperatures(vector<int> temps)
{
    vector<int> res(temps.size());
    stack<int> s;

    for (int i = temps.size()-1; i >= 0; --i) {
        while (!s.empty() && temps[i] >= temps[s.top()]) {
            s.pop();
        }
        res[i] = s.empty() ? 0 : s.top()-i;
        s.push(i); 
    }

    return res;
}

int main()
{
    vector<int> case1 {73, 74, 75, 71, 69, 72, 76, 73};
    vector<int> res1 = daily_temperatures(case1);
    for (auto &e : res1) {
        cout << e << " ";
    }
    cout << endl;

    vector<int> case2 {30, 60, 90};
    vector<int> res2 = daily_temperatures(case2);
    for (auto &e : res2) {
        cout << e << " ";
    }
    cout << endl;

    return 0;
}
