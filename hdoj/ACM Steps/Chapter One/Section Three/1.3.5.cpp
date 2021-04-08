#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

int main(void) {
#ifdef LOCAL
    freopen("1.3.5.in", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s, _s;
    int t;
    vector<int> v;
    while (getline(cin, _s, '\n')) {
        v.clear();
        stringstream _cin(_s);
        while (getline(_cin, s, '5')) {
            if (s != "\n" && s != "") {
                stringstream ss(s);
                ss >> t;
                v.push_back(t);
            }
        }
        sort(v.begin(), v.end(), less<int>());
        bool _flag = true;
        for (auto& e : v) {
            if (_flag) {
                _flag = false;
            }
            else {
                cout << " ";
            }
            cout << e;
        }
        cout << endl;
    }
    
    return 0;
}
