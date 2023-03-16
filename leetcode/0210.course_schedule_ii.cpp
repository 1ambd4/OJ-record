#include <iostream>
#include <vector>

#include  "leetcode.h"

using namespace std;

vector<int> find_order(int n, vector<vector<int>>& prerequisites)
{
    vector<int> res;
    vector<vector<int>> graph(n, vector<int>());

    for (const auto& e : prerequisites) {
        graph[e[1]].push_back(e[0]);
    }

    bool cycle = false;
    vector<bool> visit(n, false), path(n, false);
    auto traverse = [&res, &visit, &path, &cycle](auto&& self, vector<vector<int>>& graph, int u) -> void {
        if (path[u]) cycle = true;

        if (visit[u] || cycle) return ;

        visit[u] = true;
        path[u] = true;
        for (const auto& v : graph[u]) {
            // if (!visit[v]) {             // 不能加，因为如果path[v]为真的话，visit[v]必为真
            //     self(self, graph, v);    // 如果这里的剪枝会把有环的情况跳过
            // }

            self(self, graph, v);
        }
        path[u] = false;
        res.push_back(u);                   // 这里注意最终返回的结果应该是逆序后的res
                                            // 即逆后序
                                            // 因为是个有环图，故而并不能用前序
                                            // 如测试用例2
    };

    for (int i = 0; i < n; ++i) {
        // if (!visit[i]) {                 // 可以加，但没必要
        //     traverse(traverse, graph, i);
        // }
        traverse(traverse, graph, i);
    }

    return cycle ? vector<int>() : vector<int>(res.rbegin(), res.rend());
}


// 还是bfs容易捏
vector<int> _find_order(int n, vector<vector<int>>& prerequisites)
{
    vector<int> res;
    vector<vector<int>> graph(n, vector<int>());
    vector<int> indegree(n, 0);

    for (const auto& e : prerequisites) {
        graph[e[1]].push_back(e[0]);
        ++indegree[e[0]];
    }

    queue<int> q;
    for (int i = 0; i < n; ++i) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int n = q.size();
        for (int i = 0; i < n; ++i) {
            int u = q.front();
            q.pop();
            res.push_back(u);

            for (const auto& v : graph[u]) {
                if (--indegree[v] == 0) q.push(v);
            }
        }
    }

    return res.size() == n ? res : vector<int>();
}

int main()
{
    vector<vector<int>> prerequisites1 {{1,0}};
    vector<int> res1 = find_order(2, prerequisites1);
    cout << res1 << endl;

    vector<vector<int>> prerequisites2 {{1,0},{2,0},{3,1},{3,2}};
    vector<int> res2 =  find_order(4, prerequisites2);
    cout << res2 << endl;

    vector<vector<int>> prerequisites3 {};
    vector<int> res3 = find_order(1, prerequisites3);
    cout << res3 << endl;

    vector<vector<int>> prerequisites4 {{1,0},{1,2},{0,1}};
    vector<int> res4 = find_order(3, prerequisites4);
    cout << res4 << endl;

    return 0;
}

