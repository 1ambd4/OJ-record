#include <iostream>
#include <set>
#include <cstring>
#include <sstream>
using namespace std;

set<string> ss;

int main(void) {
#ifdef LOCAL
    freopen("2072.in", "r", stdin);
#endif
    string s;
    stringstream _s;
    while (getline(cin, s)) {
        //stringstream _s(s);
        _s.str(s);
        cout << _s.str() << endl;
        while (_s >> s) {
            if (s == "#") return 0;
            ss.insert(s);
        }
        cout << ss.size() << endl;
        ss.clear();
    }
    return 0;
}
