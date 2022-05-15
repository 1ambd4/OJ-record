#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Trie {
    public:
        Trie() : child(26), is_word(false) { }

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

        bool search(string word)
        {
            Trie *result = search_prefix(word);
            return result != nullptr && result->is_word;
        }

        bool startsWith(string prefix)
        {
            return search_prefix(prefix) != nullptr;
        }

    private:
        Trie* search_prefix(string prefix)
        {
            Trie *cur = this;
            for (char c : prefix) {
                c -= 'a';
                if (cur->child[c] == nullptr) {
                    return nullptr;
                }
                cur = cur->child[c];
            }
            return cur;
        }

        vector<Trie*> child;
        bool is_word;
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
