#include <iostream>
#include <vector>
#include <string>

using namespace std;

// 递归虽然在 call function 有额外开销，耐不住简洁易懂啊（不是
void reverse(vector<char>& s, int left, int right)
{
    if (left >= right) {
        return ;
    }

    swap(s[left], s[right]);

    reverse(s, left+1, right-1);
}

void reverse_string(vector<char>& s)
{
    reverse(s, 0, s.size() - 1);
}

int main()
{
    vector<char> case1 { 'h', 'e', 'l', 'l', 'o' };
    reverse_string(case1);
    for (int i = 0; i < case1.size(); ++i) {
        cout << case1[i] << " ";
    }
    cout << endl;
    
    vector<char> case2 { 'H', 'a', 'n', 'n', 'a', 'h' };
    reverse_string(case2);
    for (int i = 0; i < case2.size(); ++i) {
        cout << case2[i] << " ";
    }
    cout << endl;
    return 0;
}
