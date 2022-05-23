#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int open_lock(vector<string>& deadends, string target)
{
    int cnt = 0;
    queue<string> q;
    unordered_set<string> v(deadends.begin(), deadends.end());

    if (v.count("0000")) return -1;
    
    auto up = [](string s, int k) -> string {
        s[k] == '9' ? s[k] = '0' : s[k] += 1;
        return s;
    };
    auto down = [](string s, int k) -> string {
        s[k] == '0' ? s[k] = '9' : s[k] -= 1;
        return s;
    };
    
    string cur;
    q.push("0000");
    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; ++i) {
            cur = q.front();
            q.pop();
            if (cur == target) {
                return cnt;
            }
            for (int j = 0; j < 4; ++j) {
                string u = up(cur, j);
                string d = down(cur, j);
                if (!v.count(u)) {
                    q.push(u);
                    v.emplace(u);
                }
                if (!v.count(d)) {
                    q.push(d);
                    v.emplace(d);
                }
            }
        }
        ++cnt;
    }

    return -1;
}

int openLock(vector<string>& deadends, string target) {
    int cnt = 0;
    queue<string> q;
    unordered_map<string, bool> m, d;
    for (const auto& deadend : deadends) d[deadend] = true;
    auto up = [](string s, int k) -> string {
        s[k] == '9' ? s[k] = '0' : s[k] += 1;
        return s;
    };
    auto down = [](string s, int k) -> string {
        s[k] == '0' ? s[k] = '9' : s[k] -= 1;
        return s;
    };
    string cur;
    q.push("0000"), m["0000"] = true;
    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; ++i) {
            cur = q.front();
            q.pop();
            if (d.count(cur)) {
                continue;
            }
            if (cur == target) {
                return cnt;
            }
            for (int j = 0; j < 4; ++j) {
                string u = up(cur, j);
                string d = down(cur, j);
                // 三目运算符要求第二第三操作数类型相同
                // m.count(u) ? 1 : m[u] = true, q.push(u), 1;  // 可为啥换个位置就TLE了呢？
                // m.count(d) ? 1 : m[d] = true, q.push(d), 1;
                !m.count(u) ? m[u] = true, q.push(u), 1 : 1;
                !m.count(d) ? m[d] = true, q.push(d), 1 : 1;

            }
        }
        ++cnt;
    }

    return -1;
}

int main()
{
    vector<string> deadends1 {"0201", "0101", "0102", "1212", "2002"};
    string target1 = "0202";
    cout << open_lock(deadends1, target1) << endl;

    vector<string> deadends2 {"8887", "8889", "8878", "8898", "8788", "8988", "7888", "9888"};
    string target2 = "8888";
    cout << openLock(deadends2, target2) << endl;
    return 0;
}
