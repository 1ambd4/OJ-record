#include <iostream>
#include <vector>
#include <string>

using namespace std;

// 不含前导零，那么符合题意的必然是111...000...的形式
// 故而正序找到第一个不是1,倒序找到第一个不是0
// 这两个位置必然是紧挨着的，否则不符合题意
bool check_ones_segment(string s)
{
    int l = 0, r = s.size()-1;

    while(s[l] == '1') ++l;
    while(s[r] == '0') --r;

    return l - r == 1;
}

int main()
{
    string s1 {"1001"};
    cout << check_ones_segment(s1) << endl;

    string s2 {"110"};
    cout << check_ones_segment(s2) << endl;

    return 0;
}

