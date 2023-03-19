#include <iostream>
#include <vector>
#include <cmath>
#include <queue>

#include "leetcode.h"

using namespace std;

// 这题是无向图捏
// 概率是要相乘的，但如果取对数之后，乘法就变成了加法，是一个优化的方向
double max_probability(int n, vector<vector<int>>& edges, vector<double>& succ, int start, int end)
{
    using pii = pair<int, double>;
    vector<vector<pii>> graph(n);
    vector<double> dis(n, 1);
    vector<bool> visit(n, false);
    for (int i = 0; i < edges.size(); ++i) {
        int f = edges[i][0], t = edges[i][1];
        double p = succ[i];
        graph[f].emplace_back(t,p);
        graph[t].emplace_back(f,p);
    }


    auto cmp = [](pii& a, pii& b) {
        return a.second < b.second;
    };
    priority_queue<pii, vector<pii>, decltype(cmp)> q(cmp);
    q.push(pii(start,1));
    dis[start] = 1;

    while (!q.empty()) {

        auto [cx, cp] = q.top(); q.pop();
        // TLE了就加visit捏
        if (visit[cx]) continue;
        visit[cx] = true;

        for (const auto& [nx, np] : graph[cx]) {
            double dist = dis[cx] * np;
            if (dis[nx] == 1 || dis[nx] < dist) {
                dis[nx] = dist;
                q.push(pii(nx, dist));
            }
        }
    }

    return dis[end] != 1 ? dis[end] : 0;
}

int main()
{
    vector<vector<int>> edges1 {{0,1},{1,2},{0,2}};
    vector<double> succ1 {0.5,0.5,0.2};
    cout << max_probability(3, edges1, succ1, 0, 2) << endl;

    vector<vector<int>> edges2 {{0,1},{1,2},{0,2}};
    vector<double> succ2 {0.5,0.5,0.3};
    cout << max_probability(3, edges2, succ2, 0, 2) << endl;

    vector<vector<int>> edges3 {{0,1}};
    vector<double> succ3 {0.5};
    cout << max_probability(3, edges3, succ3, 0, 2) << endl;

    vector<vector<int>> edges4 {{1,4},{2,4},{0,4},{0,3},{0,2},{2,3}};
    vector<double> succ4 {0.37,0.17,0.93,0.23,0.39,0.04};
    cout << max_probability(5, edges4, succ4, 3, 4) << endl;
    return 0;
}

