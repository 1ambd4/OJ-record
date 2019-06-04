#include <iostream>
using namespace std;

const int MAX = 100000 + 5;
typedef long long ll;

struct NODE {
    ll sum;
    int l, r;
};

int num[MAX];
NODE tree[MAX<<2];

void build(int rt, int l, int r) {
    tree[rt].l = l;
    tree[rt].r = r;

    if (l == r) {
        tree[rt].sum = num[l];
        return ;
    }

    int mid = (l + r) >> 1;
    build(rt<<1, l, mid);
    build(rt<<1 | 1, mid + 1, r);
}

void update(int rt, int l, int r, int val) {
    if (tree[rt].l > r || tree[rt].r < l) {
        return ;
    }

    if (tree[rt].l == l && tree[rt].r == r) {
        tree[rt].sum += (r - l + 1) * val;
        return ;
    }

    int mid = (tree[rt].l + tree[rt].r) >> 1;
    LL sum = 0;
    if (rt <)
}

int main(void) {
#ifdef LOCAL
    freopen("3468.in", "r", stdin);
#endif
    char ch;
    int n, q, x, y;
    while (cin >> n >> q) {
        for (int i = 0; i < n; ++i) {

        }
        for (int i = 0; i < q; ++i) {
            cin >> ch >> x >> y;
        }
    }
    return 0;
}
