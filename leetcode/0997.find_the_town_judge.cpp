#include <iostream>
#include <vector>

using namespace std;

int find_judge(int n, vector<vector<int>>& trust)
{
    vector<vector<int>> graph = [&]() {
        vector<vector<int>> g(n+1, vector<int>(n+1, 0));

        for (const auto& elem : trust) {
            graph[elem[0]][elem[1]] = 1;
        }

        return g;
    }();

    auto knows = [&graph](int i, int j) -> bool {
        return graph[i][j] == 1;
    };

    int cur = 1;
    for (int i = 1; i <= n; ++i) {
        if (knows(cur,i)) {
            cur = i;
        }
    }

    for (int i = 1; i <= n; ++i) {
        if (i != cur && (knows(cur, i) || !knows(i, cur))) {
            return -1;
        }
    }

    return cur;
}


// 评论区解法
// https://leetcode.cn/problems/find-the-town-judge/solution/zhao-dao-xiao-zhen-de-fa-guan-by-leetcod-0dcg/1288933
int find_judge_(int n, vector<vector<int>>& trust)
{
    vector<int> trusted(n+1, 0);
    // 类似投票的思想
    // 每个人手里最多最n-1票，可以弃票，但不能投给自己
    // 当选的条件为获得n-1票且一票未投出
    for (const auto& elem : trust) {
        --trusted[elem[0]];
        ++trusted[elem[1]];
    }

    for (int i = 1; i <= n; ++i) {
        if (trusted[i] == n - 1) {
            return i;
        }
    }

    return -1;
}


int main()
{
    vector<vector<int>> trust1 { {1,2} };
    cout << find_judge_(2, trust1) << endl;

    vector<vector<int>> trust2 { {1,3}, {2,3} };
    cout << find_judge_(3, trust2) << endl;

    vector<vector<int>> trust3 { {1,3}, {2,3}, {3,1} };
    cout << find_judge_(3, trust3) << endl;
    return 0;
}

