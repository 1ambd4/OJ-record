#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

int main()
{
    vector<string> input1 { "wordsFrequency","get","get","get","get","get" };

    unordered_map<string, int> cnt;
    for (const string& s : input1) {
        ++cnt[s];
    }

    cout << cnt["get"] << endl;
    cout << cnt["got"] << endl;

    return 0;
}
