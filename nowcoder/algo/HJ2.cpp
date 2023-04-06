#include <iostream>

using namespace std;

int main()
{
    string s;
    char c;
    cin >> s >> c;

    int cnt = 0;
    for (int i = 0; i < s.size(); ++i) {
        if ((s[i] | 0b10'0000) == (c | 0b10'0000)) ++cnt;
    }
    cout << cnt << endl;
    return 0;
}
