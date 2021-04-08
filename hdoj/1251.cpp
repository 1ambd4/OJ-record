#include <iostream>
#include <cstring>
using namespace std;

const int MAX = 1e6 + 10;

int tree[MAX][30];
int sum[MAX];
int tot;

namespace lttzz {
    void insert(char* s) {
        int len = strlen(s);
        int root = 0;
        for (int i = 0; i < len; ++i) {
            int id = s[i] - 'a';
            if (!tree[root][id]) tree[root][id] = ++tot;
            sum[tree[root][id]]++;
            root = tree[root][id];
        }
    }

    int find(char* s) {
        int len = strlen(s);
        int root = 0;
        for (int i = 0; i < len; ++i) {
            int id = s[i] - 'a';
            if (!tree[root][id]) return 0;
            root = tree[root][id];
        }
        return sum[root];
    }
}

int main(void) {
#ifdef LOCAL
    freopen("1251.in", "r", stdin);
#endif
    char s[20];
    while (1) {
        cin.getline(s, 15);
        if (s[0]  == ' ' || strlen(s) == 0) break;
        lttzz::insert(s);
    }
    while  (cin >> s) {
        cout << lttzz::find(s) << endl;
    }
    return 0;
}
