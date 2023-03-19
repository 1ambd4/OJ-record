#include <iostream>
#include <vector>
#include <queue>
#include <array>
#include <limits>
#include <algorithm>
#include <cmath>

#include "leetcode.h"

using namespace std;

// 并查集的想法太巧妙了
// 首先这题可以上下左右四个方向移动，使得不好写状态转移方程，因而动态规划不适用
// bfs的思路很容易想到，并查集是不好想的
//
// 可以给每个点一个id，那么每个点和上下左右四个点之间都有一条权重为高度差的边
// 那以此构建边集（大小为m*n
// 将边升序排序，逐次连接起来
// 当某一时刻左上角和右下角联通的时候，此时的边的权重即为答案
// 会不会多加了边？会的，但是并不影响最终的答案
// 因为已经将边升序排序了，较小边不会影响到其后比它大的边
int minmum_effort_path(vector<vector<int>>& heights)
{
    int m = heights.size(), n = heights[0].size();
    vector<vector<int>> edges;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            // 秒啊，二维拉成了一维
            int id = i * n + j;
            if (i > 0) edges.push_back({id-n, id, abs(heights[i][j] - heights[i-1][j])});
            if (j > 0) edges.push_back({id-1, id, abs(heights[i][j] - heights[i][j-1])});
        }
    }

    sort(edges.begin(), edges.end(), [](vector<int>& a, vector<int>& b){
            return a[2] < b[2];
    });

    vector<int> parent(m*n), size(m*n, 0);
    for (int i = 0; i < m * n; ++i) parent[i] = i;

    auto find = [&parent](int x) {
        while (parent[x] != x) {
            parent[x] = parent[parent[x]];
            x = parent[x];
        }
        return x;
    };

    auto merge = [&parent, &size, &find](int x, int y) -> bool {
        int rx = find(x), ry = find(y);

        if (rx == ry) return false;

        if (size[rx] > size[ry]) {
            parent[ry] = rx;
            size[rx] += size[ry];
        } else {
            parent[rx] = ry;
            size[ry] += size[rx];
        }

        return true;
    };

    for (const auto& edge : edges) {
        merge(edge[0], edge[1]);
        if (find(0) == find(m*n-1)) return edge[2];
    }

    // 返回0,以防止有[[3]]这种情况
    return 0;
}

int _minmum_effort_path(vector<vector<int>>& heights)
{
    int m = heights.size(), n = heights[0].size();
    vector<vector<bool>> visit(m, vector<bool>(n, false));
    vector<vector<int>> dis(m, vector<int>(n, numeric_limits<int>::max()));

    // TODO
    // 这里为啥要用大于呢？
    auto cmp = [](array<int, 3>& a, array<int, 3>& b) -> bool {
        return a[2] > b[2];
    };

    priority_queue<array<int, 3>, vector<array<int, 3>>, decltype(cmp)> q(cmp);
    q.push({0,0,0});
    dis[0][0] = 0;


    vector<pair<int, int>> dirs = {{1,0},{-1,0},{0,1},{0,-1}};

    vector<vector<vector<vector<int>>>> adjs(m, vector<vector<vector<int>>>(n));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            for (const auto& [dx, dy] : dirs) {
                int nx = i + dx, ny = j + dy;
                if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;

                int h = abs(heights[i][j] - heights[nx][ny]);

                adjs[i][j].push_back({nx,ny,h});
            }
        }
    }

    // 函数调用过多可能TLE
    auto adj = [&adjs](int x, int y) -> vector<vector<int>> {
    // auto adj = [&heights, &dirs, m, n](int x, int y) -> vector<vector<int>> {
        // vector<vector<int>> res;
        // for (const auto& [dx, dy] : dirs) {
        //     int nx = x + dx, ny = y + dy;

        //     if (nx < 0 || nx >= m || ny < 0 | ny >= n) continue;

        //     // int height = abs(heights[x][y] - heights[dx][dy]);
        //     int height = abs(heights[x][y] - heights[nx][ny]);
        //     res.push_back({nx,ny,height});
        // }
        return adjs[x][y];
    };

    while (!q.empty()) {
        auto [ux, uy, uc] = q.top();
        q.pop();
        // 这里一次计算不可能得到正确的结果的
        // 因而加了visit反而会出错
        // 那么如何确保程序的有穷性呢？
        // 实际上，当只有使得dis更新时才往队列里添加元素已经可以做到这一点了
        // 因为最小值终究是存在的，那么必然会收紧问题的规模
        if (visit[ux][uy]) continue;

        visit[ux][uy] = true;

        for (const auto& v : adj(ux, uy)) {
            int vx = v[0], vy = v[1], vc = v[2];
            int dist = max(vc, dis[ux][uy]);
            if (dist < dis[vx][vy]) {
                dis[vx][vy] = dist;
                q.push({vx, vy, dis[vx][vy]});
            }
        }
    }

    return dis[m-1][n-1];
}

int main()
{
    vector<vector<int>> heights1 {{1,2,2},{3,8,2},{5,3,5}};
    cout << minmum_effort_path(heights1) << endl;

    vector<vector<int>> heights2 {{1,2,3},{3,8,4},{5,3,5}};
    cout << minmum_effort_path(heights2) << endl;

    return 0;
}

