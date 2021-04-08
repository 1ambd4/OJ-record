#include <iostream>
#include <cstring>
using namespace std;

const int MAX = 1e7 + 10;
char *num = new char[MAX];

inline bool quick_in(char *p) {
    char c;
    while ((c = getchar()) != EOF && (c == ' ' || c == '\n'));
    if (c == EOF) return false;
    do {
        *p++ = c;
    }while ((c = getchar()) != EOF && c != ' ' && c != '\n');
    *p = 0;
    return true;
}

inline void quick_out(char *p) {
    while (*p) putchar(*p++);
}

int main(void) {
#ifdef LOCAL
    freopen("a.in", "r", stdin);
#endif
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    int T;
    scanf("%d", &T);
    while (T--) {
        quick_in(num);
        //quick_out(num); cout << endl;

        unsigned long long len = strlen(num);

        bool flag = true;
        if (len % 4 != 0) {
            flag = false;
            cout << "No" << endl;
            continue;
        }
        unsigned long long _len = len / 4;
        for (unsigned long long i =  0; i < _len; ++i) if (num[i*4] != '2' || num[i*4+1] != '0' || num[i*4+2] != '5' || num[i*4+3] != '0') {
            flag = false;
        }
        if (flag) cout << "Yes" << endl;
        else cout << "No" << endl;
        memset(num, 0, sizeof(num));
    }
    return 0;
}