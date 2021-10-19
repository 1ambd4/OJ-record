#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Trie {
public:
    Trie() : child(26), is_word_(false) { }

    void insert(string word)
    {
        Trie *node = this;

        for (char ch : word) {
            ch -= 'a';
            if (node->child[ch] == nullptr) {
                node->child[ch] = new Trie();
            }
            node = node->child[ch];
        }
        node->is_word_ = true;
    }

    inline bool is_word() { return is_word_; }

    vector<Trie*> child;
    bool is_word_;
};

class WordDictionary {
public:
    WordDictionary()
    {
        trie = new Trie();
    }

    void add_word(string word)
    {
        trie->insert(word);
    }

    bool search(string word)
    {
        return dfs(word, trie, 0);
    }

    bool dfs(const string& word, Trie *node, int index)
    {
        if (index == word.size()) {
            return node->is_word();
        }

        // 通配符的时候搜索全部的26棵子树
        char ch = word[index];
        if (ch >= 'a' && ch <= 'z') {
            Trie *child = node->child[ch-'a'];
            if (child != nullptr && dfs(word, child, index+1)) {
                return true;
            }
        } else if (ch == '.') {
            for (int i = 0; i < 26; ++i) {
                Trie *child = node->child[i];
                if (child != nullptr && dfs(word, child, index+1)) {
                    return true;
                }
            }
        }

        return false;
    }
private:
    Trie *trie;
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
