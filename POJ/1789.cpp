#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

const int MAX = 2000 + 10;
const int INF = 0x3f3f3f3f;

int dis[MAX][MAX];
int lowc[MAX];
bool vis[MAX];

int prim(int n) {
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        lowc[i] = dis[0][i];
        vis[i] = false;
    }
    vis[0] = true;
    for (int i = 1; i < n; ++i) {
        int minc = INF;
        int p = -1;
        for (int j = 0; j < n; ++j) {
            if (!vis[j] && minc > lowc[j]) {
                minc = lowc[j];
                p = j;
            }
        }
        vis[p] = true;
        ans += minc;
        for (int j = 0; j < n; ++j) {
            if (!vis[j] && lowc[j] > dis[p][j]) {
                lowc[j] = dis[p][j];
            }
        }
    }
    return ans;
}

inline int get_dis(string s1, string s2) {
    int cnt = 0;
    for (int i = 0; i < 7; ++i) {
        if (s1[i] != s2[i]) {
            cnt++;
        }
    }
    return cnt;
}

char s[MAX][8];

int main(void) {
#ifdef LOCAL
    freopen("1789.in", "r", stdin);
#endif
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    int n;
    while (cin >> n) {
        if (n == 0) break;
        memset(lowc, 0, sizeof(lowc));
        //memset(dis, 0, sizeof(dis));
        for (int i = 0; i < n; ++i) {
            //cin >> s[i];
            scanf("%s", s[i]);
        }
        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; j++) {
                int tmp = get_dis(s[i], s[j]);
                dis[i][j] = tmp;
                dis[j][i] = tmp;
            }
        }
        //cout << prim(n) << endl;
        cout << "The highest possible quality is 1/" << prim(n) << "." << endl;
    }
    return 0;
}