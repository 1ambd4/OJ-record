#include <iostream>
#include <vector>

using  namespace std;

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
bool can_finish(int num_courses, vector<vector<int>>& prerequisites)
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
