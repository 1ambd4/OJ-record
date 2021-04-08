#include <iostream>
using namespace std;

struct {
    int h, m, s;
}t[3];
int v[2];

int main(void) {
#ifdef LOCAL
    freopen("2033.in", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        v[0] = v[1] = 0;
        cin >> t[1].h >> t[1].m >> t[1].s >> t[2].h >> t[2].m >> t[2].s;
        t[0].s = (t[1].s + t[2].s) % 60;
        v[0] = (t[1].s + t[2].s) / 60;       
        t[0].m = (t[1].m + t[2].m) % 60;
        v[1] = (t[1].m + t[2].m) / 60;
        t[0].h = t[1].h + t[2].h;
        cout << t[0].h + v[1] << " " << t[0].m + v[0]<< " " << t[0].s << endl;
    }
    
    return 0;
}
