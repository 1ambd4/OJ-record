#include <iostream>
using namespace std;

const int MAX = 100 + 5;
int n, m;
int mp[MAX][MAX], dp[MAX][MAX];
int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int dfs(int x, int y) {
    if (dp[x][y]) return dp[x][y];
    int ans = 1;
    for (int i = 0; i < 4; ++i) {
        int nx = x + dir[i][0];
        int ny = y + dir[i][1];
        if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
            if (mp[nx][ny] > mp[x][y]) {
                ans = max(ans, dfs(nx, ny) + 1);
            }
        }
    }
    dp[x][y] = ans;
    return ans;
}

int main(void) {
#ifdef LOCAL
    freopen("1088.in", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    while (cin >> n >> m) {
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> mp[i][j];
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                ans = max(ans, dfs(i, j));
            }
        }
        cout << ans << endl;
    }
    return 0;
}
