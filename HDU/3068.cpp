#include <iostream>
#include <cstring>
using namespace std;

const int MAX = 220000 + 10;
char a[MAX], s[MAX];
int p[MAX];

int manacher() {
    int id = 0, mx = 0, ans = 0;
    s[0] = '$', s[1] = '#';
    int len1 = strlen(a);
    for (int i = 0; i < len1; ++i) {
        s[i*2+2] = a[i];
        s[i*2+3] = '#';
    }
    int len2 = len1 * 2 + 2;
    s[len2] = '\0';

    for (int i = 0; i < len2; ++i) {
        p[i] = mx > i ? min(p[2*id-i], mx - i) : 1;
        while (s[i+p[i]] ==  s[i-p[i]]) ++p[i];
        if (i+p[i] > mx) {
            mx = i + p[i];
            id = i;
        }
        ans = max(ans, p[i] - 1);
    }
    return ans;
}

int main(void) {
#ifdef LOCAL
freopen("3068.in", "r", stdin);
#endif
    while (scanf("%s", a) != EOF) {
        printf("%d\n", manacher());
    }
    return 0;
}