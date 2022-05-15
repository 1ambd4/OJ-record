#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

class MapSum {
public:
    MapSum() : child(26), val(0) { }

    void insert(string key, int val)
    {
        MapSum *cur = this;
        for (auto& c : key) {
            c -= 'a';
            if (cur->child[c] == nullptr) {
                cur->child[c] = new MapSum();
            }
            cur = cur->child[c];
        }
        cur->val = val;
    }

    int sum(string prefix)
    {
        MapSum *cur = this;
        for (auto& c : prefix) {
            c -= 'a';
            if (cur->child[c] == nullptr) {
                return 0;
            }
            cur = cur->child[c];
        }
        
        int  res = 0;
        queue<MapSum*> q;
        q.push(cur);
        while (!q.empty()) {
            cur = q.front();
            q.pop();
            res += cur->val;
            for (int i = 0; i < 26; ++i) {
                if (cur->child[i] != nullptr) {
                    q.push(cur->child[i]);
                }
            }
        }

        return res;
    }
private:
    vector<MapSum*> child;
    int val;
};

int main()
{
    MapSum *trie1 = new MapSum();
    trie1->insert("apple", 3);
    cout << trie1->sum("ap") << endl;
    trie1->insert("app", 2);
    cout << trie1->sum("ap") << endl;
    return 0;
}
