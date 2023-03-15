#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> all_paths_source_target(vector<vector<int>>& graph)
{
    vector<vector<int>> res;
    vector<int> path;
    int n = graph.size() - 1;

    auto traverse = [&res, &path, &n](auto&& self, vector<vector<int>>& graph, int s) -> void {
        if (s == n) {                       // 保存结果
            res.push_back(path);
            return ;
        }

        for (const auto& v : graph[s]) {    // 遍历所有的选择
            path.push_back(v);              // 选择
            self(self, graph, v);           // 递归
            path.pop_back();                // 回溯，撤销选择
        }
    };

    path.push_back(0);                      // 必然是从节点0开始的

    traverse(traverse, graph, 0);

    return res;
}

vector<vector<int>> _all_paths_source_target(vector<vector<int>>& graph)
{
    vector<vector<int>> res;
    vector<int> path;
    int n = graph.size();

    auto traverse = [&res, &path, &n](auto&& self, vector<vector<int>>& graph, int s) -> void {
        path.push_back(s);

        if (s == n - 1) {
            res.push_back(path);
            path.pop_back();
            return ;
        }

        for (const auto& v : graph[s]) {
            self(self, graph, v);
        }

        path.pop_back();


    };

    traverse(traverse, graph, 0);

    return res;
}

void traverse(vector<vector<int>>& graph, vector<vector<int>>& res,
        vector<int>& path, int s)
{
    path.push_back(s);

    if (s == graph.size()-1) {
        res.push_back(path);
        path.pop_back();
        return ;
    }

    for (const int& vertex : graph[s]) {
        traverse(graph, res, path, vertex);
    }

    path.pop_back();
}

vector<vector<int>> __all_paths_source_target(vector<vector<int>>& graph)
{
    vector<vector<int>> res;
    vector<int> path;
    traverse(graph, res, path, 0);
    return res;
}

int main()
{
    vector<vector<int>> graph1{{1,2},{3},{3},{}};
    vector<vector<int>> res1 = all_paths_source_target(graph1);
    for (const auto& vertex : res1) {
        for (const auto& e : vertex) {
            cout << e << ',';
        }
        cout << '#';
    }
    cout << endl;

    vector<vector<int>> graph2{{4,3,1},{3,2,4},{3},{4},{}};
    vector<vector<int>> res2 = all_paths_source_target(graph2);
    for (const auto& vertex: res2) {
        for (const auto& e : vertex) {
            cout << e << ',';
        }
        cout << '#';
    }
    cout << endl;
    return 0;
}
