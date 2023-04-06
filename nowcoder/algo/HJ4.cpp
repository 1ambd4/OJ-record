#include <iostream>

using namespace std;

int main()
{
    string s;
    cin >> s;

    int n = s.size();
    if (n % 8 != 0) {
        s.append((8 - n % 8), '0');
    }
    n = s.size() / 8;

    for (int i = 0; i < n; ++i) {
        // printf(" %c%c%c%c%c%c%c%c" + !i, s[i], s[i+1], s[i+2], s[i+3], s[i+4], s[i+5], s[i+6], s[i+7]);
        printf("%s\n", s.substr(8*i,8).c_str());
    }
    return 0;
}
