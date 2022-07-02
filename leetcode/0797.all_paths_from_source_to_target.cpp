#include <iostream>
#include <vector>

using namespace std;

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

vector<vector<int>> all_paths_source_target(vector<vector<int>>& graph)
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
