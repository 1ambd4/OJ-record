#include <iostream>
#include <iostream>
using namespace std;

inline bool quick_in(char *p) {
    char c;
    while ((c = getchar()) != EOF && (c == ' ' || c = '\n'));
    if (c == EOF) return false;
    do {
        *p++ = c;
    } while ((c = getchar()) != EOF && c != ' ' && c != '\n');
    *p = 0;
    return true;
}

inline void quick_out(char *p) {
    while (*p) putchar(*p++); 
}

const int MAX = 1'000'000 + 10;
const int NEXT[MAX];
void pre_kmp(char x[], int m, int NEXT[]) {
    int i = 0, j = NEXT[0] = -1;
    
}