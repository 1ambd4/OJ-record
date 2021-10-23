#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

// 最大因子
vector<int> construct_rectangle(int area)
{
    for (int i = sqrt(area + 0.5); i > 0; --i) if (!(area % i)) {
        return { area/i, i };
    }
    return { };
}

int main()
{
    vector<int> case1 = construct_rectangle(4);
    cout << case1[0] << " " << case1[1] << endl;

    vector<int> case2 = construct_rectangle(2);
    cout << case2[0] << " " << case2[1] << endl;

    return 0;
}
