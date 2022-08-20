#include <iostream>
#include <vector>
#include <string>

using namespace std;

string merge_alternately(string word1, string word2)
{
    auto it1 = word1.begin(), it2 = word2.begin();

    string res {};

    while (it1 != word1.end() && it2 != word2.end()) {
        res += *it1++;
        res += *it2++;
    }

    while (it1 != word1.end()) {
        res += *it1++;
    }
    while (it2 != word2.end()) {
        res += *it2++;
    }

    return res;
}

int main()
{
    string word1 { "abcd" }, word2 { "pq" };
    cout << merge_alternately(word1, word2) << endl;
    return 0;
}

