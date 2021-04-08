#include <iostream>
#include <cstring>
using namespace std;

const int MAX = 1e5 + 10;
int tree[MAX][30];
char chs[MAX][25];
int sum[MAX], tot = 0, cnt  = 0;

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

string find(char* s) {
    string ans = "";
    int len = strlen(s);
    int root = 0;
    for (int i = 0; i < len; ++i) {
        int id = s[i] - 'a';
        root = tree[root][id];
        ans += s[i];
        if (sum[root] == 1) return ans;
    }
    return ans;
}

int main(void) {
#ifdef LOCAL
    freopen("2001.in", "r", stdin);
#endif
    char ch[25];
    int _cnt = 0;
    while (cin >> chs[_cnt++]) {
        insert(chs[_cnt-1]);
    }
    for (int i = 0; i < _cnt; ++i) {
        cout << chs[i] << " " << find(chs[i]) << endl;
    }
    return 0;
}
