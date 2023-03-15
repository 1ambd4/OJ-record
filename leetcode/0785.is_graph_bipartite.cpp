#include <iostream>
#include <vector>
#include <queue>

#include "leetcode.h"

using namespace std;

// dfs很容易想到非联通图，但bfs很容易忽略掉
// 还有就是别面向测试用例编程，那很不好
bool is_bipartite(vector<vector<int>>& graph)
{
    int n = graph.size();
    if (n == 0 || n == 1 && graph[0].size() == 0) return true;

    vector<bool> visit(n, false), color(n, false);

    queue<int> q;

    // 需要特别注意非联通图的问题
    for (int i = 0; i < n; ++i) {
        if (!visit[i]) {
            q.push(i);
            visit[i] = true;


            // // graph[0] = []   卡bfs是吧
            // int s = 0;
            // while (s < n && graph[s].size() == 0) {
            //     visit[q.front()] = true;
            //     q.pop();
            //     q.push(++s);
            // }

            while (!q.empty()) {
                int s = q.size();
                for (int i = 0; i < s; ++i) {
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

                    // if (q.empty()) {
                    //     int t = u + 1;
                    //     while (t < n && graph[t].empty()) ++t;
                    //     if (t < n && !visit[t]) {
                    //         q.push(t);
                    //         visit[t] = true;
                    //     }
                    // }
                }

            }
        }
    }

    return true;
}

bool _is_bipartite(vector<vector<int>>& graph)
{
    bool res = true;
    int n = graph.size();
    vector<bool> visit(n, false), color(n, false);

    auto traverse = [&res, &visit, &color](auto&& self, vector<vector<int>>& graph, int v) -> void {
        if (!res) return ;

        visit[v] = true;
        for (const auto& u : graph[v]) {
            if (!visit[u]) {
                color[u] = !color[v];
                // visit[u] = true;     // u终究是变成下一个v，因而此处无需标记
                self(self, graph, u);
            } else {
                if (color[u] == color[v]) res = false;
            }
        }
    };

    for (int i = 0; i < n; ++i) {
        if (!visit[i]) {
            traverse(traverse, graph, i);
        }
    }

    return res;
}

int main()
{
    vector<vector<int>> graph1 {{1,2,3},{0,2},{0,1,3},{0,2}};
    cout << is_bipartite(graph1) << endl;

    vector<vector<int>> graph2 {{1,3},{0,2},{1,3},{0,2}};
    cout <<is_bipartite(graph2) << endl;

    vector<vector<int>> graph3 {{},{2,4,6},{1,4,8,9},{7,8},{1,2,8,9},{6,9},{1,5,7,8,9},{3,6,9},{2,3,4,6,9},{2,4,5,6,7,8}};
    cout << is_bipartite(graph3) << endl;

    vector<vector<int>> graph4 {{}};
    cout << is_bipartite(graph4) << endl;
    return 0;
}

