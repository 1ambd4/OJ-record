#include <iostream>
#include <vector>
#include <string>

using namespace std;

void reverse_string(vector<char>& s)
{
    int n = s.size();
    for (int i = 0; i < n/2; ++i) {
        char temp = s[i];
        s[i] = s[n-1-i];
        s[n-1-i] = temp;
    }
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
