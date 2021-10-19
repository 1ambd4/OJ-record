#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Trie {
public:
    Trie() : child(26), count(0) { }

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
        ++(node->count);
    }

    unsigned int search(string word)
    {
        Trie *node = this;
        for (char ch : word) {
            ch -= 'a';
            if (node->child[ch] == nullptr) {
               return 0; 
            }
            node = node->child[ch];
        }
        return node->count;
    }
private:
    vector<Trie*> child;
    unsigned int count;
};


Trie *trie = new Trie();

int word_frequency(string word)
{
    return trie->search(word);
}

int main()
{
    vector<string> input1 { "wordsFrequency","get","get","get","get","get" };
    for (const string& s : input1) {
        trie->insert(s);
    }
    cout << word_frequency("get") << endl;
    cout << word_frequency("got") << endl;
    return 0;
}
