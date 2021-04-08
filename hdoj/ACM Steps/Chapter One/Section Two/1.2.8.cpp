#include <iostream>
#include <cstring>
#include <map>
using namespace std;

map<int, const char*> m;

int main(void) {
#ifdef LOCAL
    freopen("1.2.8.in", "r", stdin);
#endif
    m.insert(make_pair(33, "Zhejiang"));
    m.insert(make_pair(11, "Beijing"));
    m.insert(make_pair(71, "Taiwan"));
    m.insert(make_pair(81, "Hong Kong"));
    m.insert(make_pair(82, "Macao"));
    m.insert(make_pair(54, "Tibet"));
    m.insert(make_pair(21, "Liaoning"));
    m.insert(make_pair(31, "Shanghai"));  
    int T, _p = 1, _d = 2, _m = 3, _y = 4, _t = 5;
    char s[5];
    scanf("%d", &T);
    while (T--) {
        scanf("%2d%4d%4d%2d%2d%s", &_p, &_t, &_y, &_m, &_d, s);
        printf("He/She is from %s,and his/her birthday is on %02d,%02d,%04d based on the table.\n", m[_p], _m, _d, _y);
    }
    return 0;
}
