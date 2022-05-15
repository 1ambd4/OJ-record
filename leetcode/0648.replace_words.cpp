#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class Trie {
public:
    Trie() : child(26), is_word(false) { };

    void insert(string word)
    {
        Trie *cur = this;
        for (char c : word) {
            c -= 'a';
            if (cur->child[c] == nullptr) {
                cur->child[c] = new Trie();
            }
            cur = cur->child[c];
        }
        cur->is_word = true;
    }

    bool replace(string word, string& prefix)
    {
        prefix = "";
        Trie *cur = this;
        for (auto& c : word) {
            prefix += c;
            c -= 'a';
            if (cur->child[c] == nullptr) {
                return false;
            }
            if (cur->child[c]->is_word) {
                return true;
            }
            cur = cur->child[c];
        }
        return false;
    }

private:
    vector<Trie*> child;
    bool is_word;
};

string replace_words(vector<string>& dictionary, string sentence)
{
    Trie *trie = new Trie();
    stringstream ss(sentence);
    string s, prefix, res;
    for (const auto& e : dictionary) {
        trie->insert(e);
    }
    while (ss >> s) {
        if (trie->replace(s, prefix)) {
            res += prefix;
        } else {
            res += s;
        }
        res += " ";
    }
    res.pop_back();
    return res;
}

int main()
{
    vector<string> dict1 { "cat", "bat", "rat" };
    string sentence1 = "the cattle was rattled by the battery";
    string res1 = replace_words(dict1, sentence1);
    cout << res1 << endl;

    vector<string> dict2 { "a", "b", "c" };
    string sentence2 = "aadsfasf absbs bbab cadsfafs";
    string res2 = replace_words(dict2, sentence2);
    cout << res2 << endl;
    return 0;
}
