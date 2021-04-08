#include <cmath>
#include <iostream>
#include <algorithm>
using namespace std;

const float EXP = 0.01;
float db[300];

int main(void) {
#ifdef LOCAL
    freopen("1003.in", "r", stdin);
#endif
    float c;
    for (int i = 2; i < 300; ++i) {
        db[i] = db[i-1] + 1.0 / i;
    }
    while(cin >> c) {
        if (fabs(c-0) < EXP) break;
        int ans = lower_bound(db, db + 300, c) - db - 1;
        // cout << db[ans] << " " << db[ans+1];
        cout << ans << " card(s)" << endl;
    }
	return 0;
}
