#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>

using namespace std;

int first_unique_char(string s)
{
    int n = s.size();
    unordered_map<char, int> position;
    queue<pair<char, int>> q;

    for (int i = 0; i < n; ++i) {
        if (!position.count(s[i])) {
            position[s[i]] = i;
            q.emplace(s[i], i);
        } else {
            position[s[i]] = -1;
            while (!q.empty() && position[q.front().first] == -1) {
                q.pop();
            }
        }
    }

    return q.empty() ? -1 : q.front().second;
}

int main()
{
    cout << first_unique_char("leetcode") << endl;
    cout << first_unique_char("loveleetcode") << endl;
    return 0;
}
