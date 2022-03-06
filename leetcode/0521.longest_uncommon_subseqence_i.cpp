#include <iostream>
#include <string>

using namespace std;

int find_lus_length(string a, string b)
{
    return a == b ? -1 : max(a.size(), b.size());
}

int main()
{
    string a1 = "aba", b1 = "cdc";
    cout << find_lus_length(a1, b1) << endl;
    string a2 = "aaa", b2 = "bbb";
    cout << find_lus_length(a2, b2) << endl;
    return 0;
}
