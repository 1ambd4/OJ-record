#include <iostream>
#include <vector>

using namespace std;


bool car_pooling(vector<vector<int>>& trips, int capacity)
{
    int len = 1000 + 5;
    vector<int> res(len, 0), diff(len, 0);

    for (const auto& trip : trips) {
        diff[trip[1]] += trip[0];
        diff[trip[2]] -= trip[0];
    }

    res[0] = diff[0];
    if (res[0] > capacity) return false;
    for (int i = 1; i < len; ++i) {
        res[i] = res[i-1] + diff[i];
        if (res[i] > capacity) return false;
    }

    return true;
}

// 和前面的差分数组不同，这里上车遵循先下后上，因而区间是左闭右开
bool _car_pooling(vector<vector<int>> &trips, int capacity)
{
    // int len = trips[trips.size()-1][2];  // 绝了
    int len = 1000 + 5;
    vector<int> res(len, 0), diff(len, 0);

    for (const vector<int> &trip : trips) {
        diff[trip[1]] += trip[0];
        if (trip[2] < len) {
            diff[trip[2]] -= trip[0];
        }
    }

    res[0] = diff[0];
    if (res[0] > capacity) return false;    // res[0]可能大于capacity
    for (int i = 1; i < len; ++i) {
        res[i] = res[i-1] + diff[i];
        if (res[i] > capacity) {
            return false;
        }
    }

    return true;
}

int main()
{
    vector<vector<int>> vec1{ {2,1,5}, {3,3,7} };
    cout << car_pooling(vec1, 4) << endl;
    cout << car_pooling(vec1, 5) << endl;

    vector<vector<int>> vec2{ {2,1,5}, {3,5,7} };
    cout << car_pooling(vec2, 5) << endl;

    vector<vector<int>> vec3{ {3,2,7}, {3,7,9}, {8,3,9} };
    cout << car_pooling(vec3, 11) << endl;

    vector<vector<int>> vec4{ {3,2,8}, {4,4,6}, {10,8,9} };
    cout << car_pooling(vec4, 11) << endl;

    vector<vector<int>> vec5{ {9,0,1}, {3,3,7} };
    cout << car_pooling(vec5, 4) << endl;

    return 0;
}
