#include <algorithm>
#include <iostream>
#include <vector>
#include <limits>
#include <queue>

#include "leetcode.h"

using namespace std;

int network_delay_time(vector<vector<int>>& times, int n, int k)
{
    using pii = pair<int, int>;
    vector<vector<pii>> graph(n+1);
    vector<int> dis(n+1, numeric_limits<int>::max());
    for (const auto& time : times) {
        int f = time[0], t = time[1], c = time[2];
        graph[f].push_back({t, c});
    }

    auto adj = [&graph](int i) {
        return graph[i];
    };

    // emm，这里似乎cmp咋写都无所谓
    // 当然小根堆有利于后面剪枝优化就是了
    auto cmp = [](pii& a, pii& b) {
        return a.second < b.second;
    };

    priority_queue<pii, vector<pii>, decltype(cmp)> q(cmp);
    q.push(pii(k,0));       // 节点k距离节点k的最小距离为0
    dis[k] = 0;

    while (!q.empty()) {
        auto [cx, cw] = q.top(); q.pop();

        for (const auto& [nx, nw] : adj(cx)) {
            int dist = dis[cx] + nw;
            if (dist < dis[nx]) {
                dis[nx] = dist;
                q.push(pii(nx, dist));
            }
        }
    }

    int res = *max_element(dis.begin()+1, dis.end());

    return res != numeric_limits<int>::max() ? res : -1;
}

// n个结点，从k出发的最短路
int _network_delay_time(vector<vector<int>>& times, int n, int k)
{
    // 建邻接表
    using pii = pair<int, int>;
    vector<vector<pii>> graph = [&times, &n]() {
        vector<vector<pii>> g(n+1);
        for (vector<int>& time : times) {
            int from = time[0];
            int to = time[1];
            int weight = time[2];
            g[from].push_back(pii(to, weight));
        }
        return g;
    }();

    // 邻接点
    auto adj = [&graph](int i){
        return graph[i];
    };

    vector<int> distances(n+1, numeric_limits<int>::max());

    auto cmp = [](pii a, pii b){
        return a.second > b.second;
    };
    priority_queue<pii, vector<pii>, decltype(cmp)> q(cmp);
    // q: (id, dist)
    q.push(pii(k, 0));
    distances[k] = 0;

    while (!q.empty()) {
        pii cur = q.top(); q.pop();

        // 我写的这是个啥啊，永远不会执行啊
        if (cur.second > distances[cur.first]) {
            continue;
        }

        for (auto nxt : adj(cur.first)) {
            int dist = distances[cur.first] + nxt.second;
            if (dist < distances[nxt.first]) {
                distances[nxt.first] = dist;
                q.push(pii(nxt.first, dist));
            }
        }
    }

    int max_time =  *max_element(distances.begin()+1, distances.end());
    if (max_time == numeric_limits<int>::max()) {
        return -1;
    } else {
        return max_time;
    }
}

int main()
{
    vector<vector<int>> times1 {{2,1,1},{2,3,1},{3,4,1}};
    cout << network_delay_time(times1, 4, 2) << endl;

    vector<vector<int>> times2 {{1,2,1}};
    cout << network_delay_time(times2, 2, 2) << endl;

    vector<vector<int>> times3 {{1,2,1}};
    cout << network_delay_time(times3, 2, 1) << endl;
    return 0;
}
