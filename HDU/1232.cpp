/*************************************************************************
	> File Name: 1232.cpp
	> Author: lttzz
	> Mail: 3344517687@qq.com 
	> Created Time: 2018-04-18 08:58:07
 ************************************************************************/

#include <iostream>
using namespace std;

const int maxn = 1005;
int pre[maxn], rnk[maxn];

void init(int n) {
    for (int i = 1; i <= n; i++) {
        pre[i] = i;
        rnk[i] = 1;
    }
}

int find(int node) {
    return pre[node] == node ? node : pre[node] = find(pre[node]);
}

int unin(int x, int y) {
    int root_1 = find(x);
    int root_2 = find(y);

    if (root_1 == root_2) {
        return 0;
    }
    if (rnk[root_1] > rnk[root_2]) {
        pre[root_2] = root_1;
        rnk[root_1] += rnk[root_2];
    }
    else {
        pre[root_1] = root_2;
        rnk[root_2] += rnk[root_1];
    }
    return 1;
}

int main(void) {
    int n, m, x, y;
    while ((cin >> n) &&n) {
        cin >> m;

        init(n);

        while (m--) {
            cin >> x >> y;
            unin(x, y);
        }

        int cnt = n - 1;
        for (int i = 1; i <= n; i++) {
            if (pre[i] != i) {
                cnt--;
            }
        }

        cout << cnt << endl;
    }
    return 0;
}

//坑: rank命名冲突.
