#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

vector<int> ConstructArray(vector<int> &a)
{
    // 本质是定义两个数组，分别维护i左侧、右侧的连乘积
    if (a.size() == 0)
        return {};

    vector<int> b(a.size(), 1);

    for (int i = 1; i < b.size(); ++i) {
        b[i] = b[i-1] * a[i-1];
    }

    for (int i = b.size() - 2, temp = 1; i >= 0; --i) {
        temp *= a[i+1];
        b[i] *= temp;
    }

    return b;
}

int main(void)
{
    vector<int> v1 = {};
    vector<int> r1 = ConstructArray(v1);
    for (auto const &e : r1) {
        cout << e << " ";
    }
    cout << endl;

    vector<int> v2 = {1, 2, 3, 4, 5};
    vector<int> r2 = ConstructArray(v2);
    for (auto const &e : r2) {
        cout << e << " ";
    }
    cout << endl;

    return 0;
}
