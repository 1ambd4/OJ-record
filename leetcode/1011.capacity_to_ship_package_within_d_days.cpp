#include <iostream>
#include <vector>

using namespace std;

// f(x)=days
int f(vector<int> &weights, int x)
{
    int days = 0, tmp = 0;
    for (int i = 0; i < weights.size(); ) {
        tmp += weights[i];
        if (tmp > x) {
            days++;
            tmp = 0;
        } else if (tmp == x) {
            days++;
            tmp = 0;
            i++;
        } else {
            i++;
            if (i == weights.size()) {
                days++;
            }
        }
    }
    return days;
}

// int f(vector<int> &weights, int x)
// {
//     int days = 0;
//     for (int i = 0; i < weights.size(); ) {
//         int cap = x;
//         while (i < weights.size()) {
//             if (cap < weights[i]) break;
//             else cap -= weights[i];
//             i++;
//         }
//         days++;
//     }
//     return days;
// }

// 寻找f(s)=day的最小s
int ship_within_days(vector<int> &weights, int days)
{
    int left = 0, right = 0 + 10;
    for (const auto &weight : weights) {
        left = max(left, weight);
        right += weight;
    }

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (f(weights, mid) == days) {
            right = mid -1;
        } else if (f(weights, mid) > days) {
            left = mid + 1;
        } else if (f(weights, mid) < days) {
            right = mid -1;
        }
    }

    return left;
}

int main()
{
    vector<int> w1 { 1,2,3,4,5,6,7,8,9,10 };
    cout << ship_within_days(w1, 5) << endl;
    vector<int> w2 { 3,2,2,4,1,4 };
    cout << ship_within_days(w2, 3) << endl;
    vector<int> w3 { 1,2,3,1,1 };
    cout << ship_within_days(w3, 4) << endl;
    return 0;
}
