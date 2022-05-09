#include <iostream>
#include <vector>
#include <string>

#include "leetcode.h"

using namespace std;

vector<int> di_string_match(string s)
{
    vector<int> res(s.size(), 0);
    int left = 0, right = s.size();
    for (int i = 0; i < s.size(); ++i) {
        res[i] = s[i] == 'I' ? left++ : right--;
    } 
    res.push_back(right);
    return res;
}

int main()
{
    string s1 = "IDID";
    vector<int> res1 = di_string_match(s1);
    cout << res1 << endl;
    return 0;
}
