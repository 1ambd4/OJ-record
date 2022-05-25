#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <queue>

using namespace std;


int ladder_length(string begin_word, string end_word, vector<string>& word_list)
{
    int cnt = 1;

    unordered_set<string> d(word_list.begin(), word_list.end());
    if (d.find(end_word) == d.end()) return 0;

    auto next = [](string s, int i, int j) -> string {
        s[i] = 'a' + j;
        return s;
    };

    unordered_set<string> q1 { begin_word }, q2 { end_word };

    while (!q1.empty() && !q2.empty()) {
        unordered_set<string> t;
        ++cnt;

        for (string cur : q1) {

            d.erase(cur);

            for (int i = 0; i < cur.size(); ++i) {
                for (int j = 0; j < 26; ++j) {
                    string n = next(cur, i, j);
                    if (d.find(n) == d.end()) continue;
                    if (q2.find(n) != q2.end()) return cnt;
                    t.emplace(n);
                }
            }
        }

        if (t.size() > q2.size()) {
            q1 = t;
        } else {
            q1 = q2;
            q2 = t;
        }
    }

    return 0;
}

int main()
{
    vector<string> list1 { "hot", "dot", "lot", "log", "cog" };
    string begin_word1 = "hit", end_word1 = "cog";
    cout << ladder_length(begin_word1, end_word1, list1) << endl;

    vector<string> list2 { "hot", "dot", "dog", "lot", "log" };
    string begin_word2 = "hit", end_word2 = "cog";
    cout << ladder_length(begin_word2, end_word2, list2) << endl;
    return 0;
}
