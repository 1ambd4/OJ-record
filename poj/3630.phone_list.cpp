#include <iostream>
#include <cstring>
using namespace std;

const int MAX = 200000 + 10;
char num[MAX][20];
int tree[MAX][15];
int sum[MAX], tot = 0;
bool flag;

void insert(char* s) {
    int len = strlen(s);
    int root = 0;
    for (int i = 0; i < len; ++i) {
        int id = s[i] - '0';
        if (!tree[root][id]) tree[root][id] = ++tot;
        sum[tree[root][id]]++;
        root = tree[root][id];
    }
}

bool find(char* s) {
    int len = strlen(s);
    int root = 0, cnt = 0;
    for (int i = 0; i < len; ++i) {
        int id = s[i] - '0';
        if (sum[tree[root][id]] >= 2) cnt++;
        root = tree[root][id];
    }
    if (cnt == len) return false;
    return true;
}

int main(void) {
#ifdef LOCAL
    freopen("3630.in", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    int T, n;
    cin >> T;
    while (T--) {
        memset(tree, 0, sizeof(tree));
        memset(sum, 0, sizeof(sum));
        tot = 0;
        flag = true;
        cin >> n;
        for (int i = 0; i < n; ++i) {
            cin >> num[i];
            insert(num[i]);
        }
        for (int i = 0; i < n; ++i) {
            if (!find(num[i])) {
                flag = false;
                break;
            }
            // cout << find(num[i]) << endl;
        }
        if (flag) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}
