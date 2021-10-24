#include <iostream>
#include <string>

using namespace std;

void reverse(string& s, int left, int right)
{
    if (left >= right) {
        return ;
    }

    swap(s[left], s[right]);

    reverse(s, left+1, right-1);
}

string reverse_words(string s)
{
    s.append(" ");
    int n = s.size();

    for (int low = 0, fast = 0; fast < n; ++fast) {
        if (s[fast] == ' ') {
            reverse(s, low, fast-1);
            fast++;
            low = fast;
        }
    }
    return s.substr(0, s.size()-1);
}

int main()
{
    string case1 { "Let's take LeetCode contest" };
    ;
    cout << reverse_words(case1) << endl;
    return 0;
}
