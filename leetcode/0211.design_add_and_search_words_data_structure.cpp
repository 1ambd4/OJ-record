#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Trie {
public:
    Trie() : child(26), is_word(false) { }

    void insert(string word)
    {
        Trie *cur = this;
        for (auto& c : word) {
            c -= 'a';
            if (cur->child[c] == nullptr) {
                cur->child[c] = new Trie();
            }
            cur = cur->child[c];
        }
        cur->is_word = true;
    }

    vector<Trie*> child;
    bool is_word;
};

class WordDictionary {
public:
    WordDictionary() {
        trie = new Trie();
    }

    void add_word(string word) {
        trie->insert(word);
    }

    bool search(string word) {
        return dfs(word, trie, 0);
    }

private:
    Trie *trie;

    bool dfs(const string& word, Trie *cur, int index)
    {
        if (index == word.size()) {
            return cur->is_word;
        }

        char c = word[index];
        if (c >= 'a' && c <= 'z') {
            Trie *child = cur->child[c-'a'];
            if (child != nullptr && dfs(word, child, index + 1)) {
                return true;
            }
        } else if (c == '.') {
            for (int i = 0; i < 26; ++i) {
                Trie *child = cur->child[i];
                if (child != nullptr && dfs(word, child, index + 1)) {
                    return true;
                }
            }
        }

        return false;
    }
};

int main()
{
    WordDictionary *dict = new WordDictionary();
    dict->add_word("bad");
    dict->add_word("dad");
    dict->add_word("mad");

    cout << dict->search("pad") << endl;
    cout << dict->search("bad") << endl;
    cout << dict->search(".ad") << endl;
    cout << dict->search("b..") << endl;
    return 0;
}
