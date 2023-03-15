#include <iostream>
#include <vector>
#include <queue>

#include "leetcode.h"

using namespace std;

bool possible_bipartition(int n, vector<vector<int>>& disklikes)
{
    vector<vector<int>> graph(n+1, vector<int>());
    auto build_graph = [&graph, &disklikes]() -> void {
        for (const auto& disklike : disklikes) {
            int u = disklike[0];
            int v = disklike[1];

            graph[u].push_back(v);
            graph[v].push_back(u);

        }

    };


    build_graph();

    bool res = true;
    vector<bool> visit(n+1, false), color(n+1, false);

    auto traverse = [&visit, &color, &res](auto&& self, vector<vector<int>>& graph, int u) -> void {
        if (!res) return ;

        for (const auto& v : graph[u]) {
            if (!visit[v]) {
                visit[v] = true;
                color[v] = !color[u];
                self(self, graph, v);
            } else {
                if (color[v] == color[u]) res = false;
            }
        }
    };

    for (int i = 1; i <= n; ++i) {
        if (!visit[i]) {
            traverse(traverse, graph, i);
        }
    }

    return res;
}

bool _possible_bipartition(int n, vector<vector<int>>& disklikes)
{
    // 注意，序号从1开始
    vector<vector<int>> graph(n+1, vector<int>());
    auto build_graph = [&graph, &disklikes]() -> void {
        for (const auto& disklike : disklikes) {
            int u = disklike[0];
            int v = disklike[1];

            graph[u].push_back(v);
            graph[v].push_back(u);

        }

    };

    build_graph();

    vector<bool> visit(n+1, false), color(n+1, false);

    queue<int> q;

    for (int i = 1; i <= n; ++i) {
        if (!visit[i]) {
            q.push(i);
            visit[i] = true;

            while (!q.empty()) {
                int s = q.size();
                for (int j = 0; j < s; ++j) {
                    int u = q.front();
                    q.pop();

                    for (const auto& v : graph[u]) {
                        if (!visit[v]) {
                            color[v] = !color[u];
                            visit[v] = true;
                            q.push(v);
                        } else {
                            if (color[u] == color[v]) return false;
                        }
                    }
                }
            }
        }
    }

    return true;
}

int main()
{
    vector<vector<int>> disklikes1 {{1,2},{1,3},{2,4}};
    cout << possible_bipartition(4, disklikes1) << endl;

    vector<vector<int>> disklikes2 {{1,2},{1,3},{2,3}};
    cout << possible_bipartition(3, disklikes2) << endl;

    vector<vector<int>> disklikes3 {{1,2},{2,3},{3,4},{4,5},{1,5}};
    cout << possible_bipartition(5, disklikes3) << endl;

    return 0;
}

