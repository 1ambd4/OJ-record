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

//     bool search(string word)
//     {
//         Trie *node = search_prefix(string(word.begin(), word.end()-1));
//         return node!=nullptr && node->is_word;
//     }
    
    // 还是要dfs啊
    // dfs(trie, result, temp)
    void dfs(Trie *trie, string& result, string& cur)
    {
       if (result.size() < cur.size()) {
          result = cur; 
       }

       for (int i = 0; i < 26; ++i) {
           if (trie->child[i] && trie->child[i]->is_word) {
               cur.push_back('a'+i);
               dfs(trie->child[i], result, cur);
               cur.pop_back();
           }
       }
    }

private:
    vector<Trie*> child;
    bool is_word;

//     Trie* search_prefix(string prefix)
//     {
//         Trie *node = this;
//         for (char ch : prefix) {
//             ch -= 'a';
//             if (node->child[ch] == nullptr) {
//                 return nullptr;
//             }
//             node = node->child[ch];
//         }
//         return node;
//     }
};

// 构建字典树，然后遍历 words，在字典树里查找是否其前缀也是一个单词
// string longest_word(vector<string>& words)
// {
//     string result;
//     Trie *trie = new Trie();
//     for (string word : words) {
//        trie->insert(word); 
//     }
// 
//     for (string word: words) {
//         if (trie->search(word)) {
//             if (result.size() < word.size() || (result.size() == word.size() && result > word)) {
//                 result = word;
//             }
//         }
//     }
//     return result;
// }

string longest_word(vector<string>& words)
{
    string result, temp;
    Trie *trie = new Trie();
    for (const auto& word : words) {
        trie->insert(word);
    }
    trie->dfs(trie, result, temp);
    return result;
}

int main()
{
    vector<string> input1 { "a", "banana", "app", "appl", "ap","apply", "apple" };
    cout << longest_word(input1) << endl;
    
    // f**k，题目也没说清楚必须要从一个字母开始拼起来啊
    vector<string> input2 { "yo","ew","fc","zrc","yodn","fcm","qm","qmo","fcmz","z","ewq","yod","ewqz","y" };
    cout << longest_word(input2) << endl;
    return 0;
}
