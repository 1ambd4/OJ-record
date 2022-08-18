#include <iostream>
#include <vector>

using namespace std;

bool are_almost_equal(string s1, string s2)
{
    int n1 = s1.size(), n2 = s2.size();
    if (n1 != n2) return false;

    vector<int> pos;

    for (int i = 0; i < n1; ++i) {
        if (s1[i] != s2[i]) {
            pos.push_back(i);
        }
    }

    if (pos.size() == 0) return true;
    if (pos.size() > 2) return false;
    if (pos.size() == 2 && s1[pos[0]] == s2[pos[1]] && s1[pos[1]] == s2[pos[0]]) return true;
    return false;
}

int main()
{
    string s1 = "bank", s2 = "kanb";
    cout << are_almost_equal(s1, s2) << endl;

    string s3 = "attack", s4 = "defend";
    cout << are_almost_equal(s3, s4) << endl;

    string s5 = "kelb", s6 = "kelb";
    cout << are_almost_equal(s5, s6) << endl;

    string s7 = "aa", s8 = "ac";
    cout << are_almost_equal(s7, s8) << endl;

    return 0;
}

