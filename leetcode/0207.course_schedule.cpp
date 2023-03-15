#include <iostream>
#include <vector>
#include <queue>

using  namespace std;

// 深搜的思路是判断有向图无环
// 广搜不妨换个思路，即有向图中所有节点必然存在某一时刻，其前置课程均被学完
// 表现在图里就是自身节点入度为0
// 当然，这只是有向图无环的另一种角度而已
bool can_finish(int n, vector<vector<int>>& prerequisites)
{
    vector<vector<int>> graph(n, vector<int>());
    vector<int> into(n, 0);
    for (const auto& e : prerequisites) {
        graph[e[1]].push_back(e[0]);
        ++into[e[0]];
    }

    queue<int> q;
    for (int i = 0; i < n; ++i) {
        if (into[i] == 0) q.push(i);     // 把入度为0的点都入队
    }

    int res = 0;
    while (!q.empty()) {
        ++res;                          // 因为入队的都是入度为0的节点，因而出队的时候结果加一即可
        int u = q.front();
        q.pop();

        for (const auto& v : graph[u]) {
            --into[v];
            if (into[v] == 0) q.push(v);
        }
    }

    return res == n;
}

// 定义边表示有前置关系构建有向图
// 那么如果可以完成需要保证有向图无环
bool _can_finish(int n, vector<vector<int>>& prerequisites)
{
    bool res = true;

    vector<vector<int>> graph(n, vector<int>());
    for (const auto& e : prerequisites) {
        graph[e[1]].push_back(e[0]);
    }

    vector<bool> visit(n, false), path(n, false);

    auto traverse = [&visit, &path, &res](auto&& self, vector<vector<int>>& graph, int u) -> void {
        if (path[u]) res = false;

        if (visit[u] || !res) return ;


        visit[u] = true;
        path[u] = true;
        for (const auto& v : graph[u]) {
            self(self, graph, v);
        }
        path[u] = false;
    };

    for (int i = 0; i < n; ++i) {
        if (!visit[i]) {
            traverse(traverse, graph, i);
        }
    }

    return res;
}

void traverse(vector<vector<int>>& graph, int s, vector<bool>& visited,
        vector<bool>& path, bool& has_cycle)
{
    if (path[s]) has_cycle = true;

    if (visited[s] || has_cycle) return ;

    path[s] = true;
    visited[s] = true;
    for (const auto& e : graph[s]) {
        traverse(graph, e, visited, path, has_cycle);
    }
    path[s] = false;
}

// 有向无环图判定
bool __can_finish(int num_courses, vector<vector<int>>& prerequisites)
{
    vector<vector<int>> graph = [&](){
        vector<vector<int>> g(num_courses, vector<int>());

        for (const auto& e : prerequisites) {
            g[e[1]].push_back(e[0]);
        }

        return g;
    }();
    vector<bool> visited(num_courses, false);
    vector<bool> path(num_courses, false);
    bool has_cycle = false;

    // 图可能不连通，因而需要对每个点进行遍历
    for (int i = 0; i < num_courses; ++i) {
        traverse(graph, i, visited, path, has_cycle);
    }

    return !has_cycle;
}

int main()
{
    vector<vector<int>> prerequisites1{{1,0}};
    cout << can_finish(2, prerequisites1) << endl;

    vector<vector<int>> prerequisites2{{1,0}, {0,1}};
    cout << can_finish(2, prerequisites2) << endl;
    return 0;
}
