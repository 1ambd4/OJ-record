#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

class Trie {
public:
    Trie() : child(26), cnt(0) { }

    void insert(string word)
    {
        Trie *node = this;
        for (char ch : word) {
            ch -= 'a';
            if (node->child[ch] == nullptr) {
                node->child[ch] = new Trie();
            }
            node = node->child[ch];
            node->cnt++;
        }
    }

    void dfs(Trie *trie, int len, string& res)
    {
        if (trie == nullptr) return;

        for (int i = 0; i < 26; ++i) {
            if (trie->child[i] && trie->child[i]->cnt == len) {
                res.push_back('a'+i);
                dfs(trie->child[i], len, res);
            }
        }
    }

private:
    vector<Trie*> child;
    int cnt;
};

string longest_common_prefix(vector<string> &strs)
{
    Trie *trie = new Trie();
    string res = "";
    for (string& str : strs) trie->insert(str);
    trie->dfs(trie, strs.size(), res);
    return res;
}

int main()
{
    vector<string> case1 { "flower", "flow", "flight" };
    cout << longest_common_prefix(case1) << endl;

    vector<string> case2 { "dog", "racecar", "car" };
    cout << longest_common_prefix(case2) << endl;

    return 0;
}
