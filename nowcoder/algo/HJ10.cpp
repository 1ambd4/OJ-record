#include <iostream>
#include <set>
#include <string>

using namespace std;

int main()
{
    set<char> st;
    string s;
    while (cin >> s) {
        st.clear();
        for (const char c: s) st.insert(c);
        cout << st.size() << endl;
    }
    return 0;
}
