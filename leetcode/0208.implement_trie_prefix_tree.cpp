#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Trie {
public:
    Trie() : child(26), is_word(false) { }

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
        node->is_word = true;
    }

    bool search(string word)
    {
        Trie *result = search_prefix(word);
        return result != nullptr && result->is_word;
    }

    bool start_with(string prefix)
    {
        return search_prefix(prefix) != nullptr;
    }
private:
    vector<Trie*> child;
    bool is_word;

    Trie* search_prefix(string prefix)
    {
        Trie *node = this;
        for (char ch : prefix) {
            ch -= 'a';
            if (node->child[ch] == nullptr) {
                return nullptr;
            }
            node = node->child[ch];
        }
        return node;
    }
};

int main()
{
    Trie *trie = new Trie();
    vector<string> input =  {"trie","insert","search","search","startsWith" };
    for (string s : input) {
        trie->insert(s);
    }


    cout << trie->search("trie") << " " << trie->search("trei") << endl;
    cout << trie->search("researh") << " " << trie->search("search") << endl;
    return 0;
}
