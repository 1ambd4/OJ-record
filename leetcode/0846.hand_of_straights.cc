#include <algorithm>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

bool is_n_straight_hand(vector<int> &hand, int group_size)
{
    if (hand.size() % group_size != 0) {
        return false;
    }

    unordered_map<int, int> cnt;
    priority_queue<int, vector<int>, greater<int>> q;

    for (auto &elem : hand) {
        cnt[elem]++;
        q.push(elem);
    }

    while (!q.empty()) {
        int num = q.top();
        q.pop();
        if (cnt[num] == 0) continue;
        for (int i = 0; i < group_size; ++i) {
            if (cnt[num+i] == 0) return false;
            --cnt[num+i];
        }
    }

    return true;
}

int main()
{
    vector<int> case1 {1, 2, 3, 6, 2, 3, 4, 7, 8};
    cout << is_n_straight_hand(case1, 3) << endl;

    vector<int> case2 {1, 2, 3, 4, 5};
    cout << is_n_straight_hand(case2, 4) << endl;

    return 0;
}
